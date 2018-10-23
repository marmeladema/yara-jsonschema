import os
import unittest
import yarajsonschema as yjs
import tempfile
import difflib

examples_dir = os.path.join(os.path.dirname(__file__), '..', 'examples', 'har')


class TestHar(unittest.TestCase):
	def assertUnifiedDiff(self, fromfile, tofile):
		with open(fromfile, 'rt') as a_fd, open(tofile, 'rt') as b_fd:
			diff = ''.join(
			    difflib.unified_diff(
			        a_fd.readlines(),
			        b_fd.readlines(),
			        fromfile = fromfile,
			        tofile = tofile
			    )
			)
			if diff:
				self.fail('\n' + diff)

	def generic(self, name):
		with tempfile.NamedTemporaryFile() as dec_fd, tempfile.NamedTemporaryFile() as set_fd:
			yjs.main(
			    [
			        os.path.join(examples_dir, name + '.json'),
			        '--dec-output',
			        dec_fd.name,
			        '--set-output',
			        set_fd.name,
			    ]
			)
			ref_dec_file = os.path.realpath(
			    os.path.join(examples_dir, name + '-dec.h')
			)
			self.assertUnifiedDiff(ref_dec_file, dec_fd.name)
			ref_set_file = os.path.realpath(
			    os.path.join(examples_dir, name + '-set.h')
			)
			self.assertUnifiedDiff(ref_set_file, set_fd.name)

	def test_pageTimings(self):
		self.generic('pageTimings')

	def test_page(self):
		self.generic('page')

	def test_entry(self):
		self.generic('page')
