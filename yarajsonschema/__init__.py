import os
import sys
import json
import jsonschema
import enum
import argparse
import urllib
import collections

class PathItemType(enum.Enum):
	STRUCT = 1
	ARRAY = 2
	DICTIONARY = 3


class WalkCallType(enum.Enum):
	PRE = 1
	POST = 2


class Walker:
	def __init__(self, resolver, pre_func, post_func):
		self._resolver = resolver
		self._pre_func = pre_func
		self._post_func = post_func

	def __call__(self, schema):
		if self._pre_func:
			self._pre_func([], schema, WalkCallType.PRE)
		self._handle_object(
		    [],
		    schema,
		)
		if self._post_func:
			self._post_func([], schema, WalkCallType.POST)

	def _handle_object(self, path, node):
		'''
			A JSON object can be translated to:
			- a structure if 'properties' is defined
			- a dictionary if 'additionalProperties' fully
			  describes its elements
			In our case 'properties' and 'additionalProperties'
			can not be mixed because YARA can not handle "partially"
			defined structure. That is why even though json-schema 
			says additionalProperties default to True, in our case
			we default to False.
		'''
		assert (node['type'] == 'object')
		properties = node.get('properties', {})
		additionalProperties = node.get('additionalProperties', False)
		if properties and additionalProperties:
			raise RuntimeError(
			    'Cannot mix properties and additionalProperties in node:\n{}'.
			    format(json.dumps(node, indent = 2))
			)

		if properties:

			for prop_name, prop_node in properties.items():
				self._handle_node(
				    path + [(PathItemType.STRUCT, prop_name)], prop_node
				)

		if additionalProperties:
			if additionalProperties == True:
				raise RuntimeError(
				    'additionalProperties should fully describes its elements in node:\n{}'.
				    format(json.dumps(node, indent = 2))
				)
			if not name:
				raise RuntimeError(
				    'additionalProperties object must be a named property in node:\n{}'.
				    format(json.dumps(node, indent = 2))
				)

			additionalProperties = self.resolve_node(additionalProperties)
			self._handle_node(path + [(PathItemType.DICTIONARY, )], prop_node)

	def _handle_array(self, path, node):
		if not path or path[-1][0] != PathItemType.STRUCT:
			raise RuntimeError(
			    'array must a be named property of parent object in node:\n{}'.
			    format(json.dumps(node, indent = 2))
			)
		items = self.resolve_node(node.get('items', {}))
		if not isinstance(items, dict):
			raise RuntimeError(
			    'array items field must be an object for node:\n{}'.format(
			        json.dumps(node, indent = 2)
			    )
			)

		self._handle_node(path + [(PathItemType.ARRAY, )], items)

	def resolve_node(self, node):
		if '$ref' in node:
			with self._resolver.resolving(node['$ref']) as ref:
				node = dict(ref)
		return node

	def _handle_node(self, path, node):
		node = self.resolve_node(node)
		if 'type' not in node:
			node['type'] = 'object'
		if isinstance(node['type'], list):
			node['type'].remove('null')
			if len(node['type']) == 1:
				node['type'] = node['type'][0]

		if self._pre_func:
			self._pre_func(path, node, WalkCallType.PRE)

		if node['type'] == 'object':
			self._handle_object(path, node)
		elif node['type'] == 'array':
			self._handle_array(path, node)
		elif node['type'] not in [
		    'null', 'boolean', 'integer', 'number', 'string'
		]:
			raise RuntimeError('invalid node type: {}'.format(node['type']))

		if self._post_func:
			self._post_func(path, node, WalkCallType.POST)


class Generator:
	def __init__(self, fd):
		self._fd = fd

	def add(self, path, line):
		self._fd.write(' ' * 2 * len(path) + line + '\n')


class DecGenerator(Generator):
	def begin(self, path, node, _):
		name = ''
		postfix = ''
		#print(path)
		if not path:
			self.add(path, 'begin_declarations;')
			return
		elif path[-1][0] == PathItemType.ARRAY:
			name = path[-2][1]
			postfix = '_array'
		elif path[-1][0] == PathItemType.DICTIONARY:
			name = path[-2][1]
			postfix = '_dictionary'
		else:
			name = path[-1][1]

		if node['type'] == 'array':
			if postfix:
				raise RuntimeError(
				    'array of array or dictionary is not supported'
				)
		elif node['type'] == 'object':
			#if postfix:
			#	raise RuntimeError('dictionary of array or dictionary is not supported')

			self.add(path, 'begin_struct' + postfix + '("' + name + '");')

	def end(self, path, node, _):
		name = ''
		postfix = ''
		#print(path)
		if not path:
			self.add(path, 'end_declarations;')
			return
		elif path[-1][0] == PathItemType.ARRAY:
			name = path[-2][1]
			postfix = '_array'
		elif path[-1][0] == PathItemType.DICTIONARY:
			name = path[-2][1]
			postfix = '_dictionary'
		else:
			name = path[-1][1]

		if node['type'] in ['boolean', 'integer']:
			self.add(path, 'declare_integer' + postfix + '("' + name + '");')
		elif node['type'] == 'number':
			self.add(path, 'declare_float' + postfix + '("' + name + '");')
		elif node['type'] == 'string':
			self.add(path, 'declare_string' + postfix + '("' + name + '");')
		elif node['type'] == 'array':
			if postfix:
				raise RuntimeError(
				    'array of array or dictionary is not supported'
				)
		elif node['type'] == 'object':
			#if postfix:
			#	raise RuntimeError('dictionary of array or dictionary is not supported')

			self.add(path, 'end_struct' + postfix + '("' + name + '");')


class SetGenerator(Generator):
	def begin(self, path, node, _):
		name = ''
		if not path:
			self.add(path, 'char path[4096] = {0}, part[128] = {0};')
			self.add(path, 'json_t *value __attribute__((unused));')
			self.add(path, 'size_t index __attribute__((unused));')
			self.add(path, 'const char *key __attribute__((unused));')
			self.add(path, 'const char *str __attribute__((unused));')
			return
		elif path[-1][0] == PathItemType.ARRAY:
			#self.add(path, 'size_t ' + 'index;')
			#self.add(path, 'json_t *' + 'value;')
			self.add(path, 'json_array_foreach(node, index, value) {')
			self.add(path, '  size_t pathlen = strlen(path);')
			self.add(
			    path,
			    '  snprintf(path+pathlen, sizeof(path)-pathlen, "[%zu]", index);'
			)
			self.add(path, '  json_t *node = value;')
		elif path[-1][0] == PathItemType.DICTIONARY:
			#self.add(path, 'const char *' + '_' * len(path) + 'key;')
			#self.add(path, 'json_t *'+ '_' * len(path) + 'value;')
			self.add(path, 'json_object_foreach(node, key, value) {')
			self.add(path, '  size_t pathlen = strlen(path);')
			self.add(
			    path,
			    '  snprintf(path+pathlen, sizeof(path)-pathlen, "[\"%s\"]", key);'
			)
			self.add(path, '  json_t *node = value;')
		else:
			self.add(path, '{')
			self.add(path, '  size_t pathlen = strlen(path);')
			self.add(path, '  if(pathlen == 0) {')
			self.add(
			    path, '    snprintf(path+pathlen, sizeof(path)-pathlen, "' +
			    path[-1][1] + '");'
			)
			self.add(path, '  } else {')
			self.add(
			    path, '    snprintf(path+pathlen, sizeof(path)-pathlen, ".' +
			    path[-1][1] + '");'
			)
			self.add(path, '  }')
			self.add(path, '  value = node;')
			self.add(
			    path, '  json_t *node = json_object_get(value, "' + path[-1][1]
			    + '");'
			)

		self.add(path, '  if(node) {')
		if node['type'] in ['boolean', 'integer']:
			self.add(
			    path,
			    '    set_integer(json_integer_value(node), module_object, path);'
			)
		elif node['type'] == 'number':
			self.add(
			    path,
			    '    set_float(json_real_value(node), module_object, path);'
			)
		elif node['type'] == 'string':
			self.add(path, '    str = json_string_value(node);')
			self.add(path, '    if(str) set_string(str, module_object, path);')
		elif node['type'] == 'array':
			#if postfix:
			#	raise RuntimeError('array of array or dictionary is not supported')

			pass
		elif node['type'] == 'object':
			#if postfix:
			#	raise RuntimeError('dictionary of array or dictionary is not supported')

			pass
		self.add(path, '  }')

	def end(self, path, node, _):
		name = ''
		if not path:
			return
		elif path[-1][0] == PathItemType.ARRAY:
			#self.add(path, '}')
			pass
		elif path[-1][0] == PathItemType.DICTIONARY:
			#self.add(path, '}')
			pass
		else:
			name = path[-1][1]

		self.add(path, '  path[pathlen] = 0;')
		self.add(path, '}')


validators = {
    'draft3': jsonschema.Draft3Validator,
    'draft4': jsonschema.Draft4Validator,
    'draft6': jsonschema.Draft6Validator,
    'draft7': jsonschema.Draft7Validator,
}

parser = argparse.ArgumentParser()
parser.add_argument('schema')
parser.add_argument(
    '--validator', choices = validators.keys(), default = 'draft7'
)
parser.add_argument(
    '--dec-output', type = argparse.FileType('w'), default = sys.stdout
)
parser.add_argument(
    '--set-output', type = argparse.FileType('w'), default = sys.stdout
)


def main(cmdline = None):
	args = parser.parse_args(cmdline or sys.argv[1:])

	with open(args.schema) as schema_fd:
		schema = json.load(schema_fd, object_pairs_hook=collections.OrderedDict)
		urlparts = list(urllib.parse.urlsplit(args.schema))
		# fallback to file:// if scheme is missing
		if not urlparts[0]:
			urlparts[0] = 'file://'
			urlparts[2] = os.path.realpath(urlparts[2])
		resolver = jsonschema.RefResolver(
		    urllib.parse.urlunsplit(urlparts), schema
		)

		validators[args.validator].check_schema(schema)

		g = DecGenerator(args.dec_output)
		w = Walker(resolver, g.begin, g.end)
		w(schema)
		args.dec_output.close()

		# Seek to end of file just in case dec_output and 
		# set_ouput refer to the same file description
		if args.set_output != sys.stdout:
			args.set_output.seek(0, os.SEEK_END)

		g = SetGenerator(args.set_output)
		w = Walker(resolver, g.begin, g.end)
		w(schema)
		args.set_output.close()

if __name__ == '__main__':
	main()
