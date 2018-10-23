import sys
import os
import glob
from setuptools import setup, find_packages

assert sys.version_info >= (3, 0)


# Utility function to read the README file.
# Used for the long_description.  It's nice, because now 1) we have a top level
# README file and 2) it's easier to type in the README file than to put a raw
# string in below ...
def read(fname):
	return open(os.path.join(os.path.dirname(__file__), fname)).read()


setup(
    name = 'yarajsonschema',
    version = '0.1',
    author = 'Elie ROUDNINSKI',
    author_email = 'xademax@gmail.com',
    description = (
        'YARA module object generator based on json-schema description'
    ),
    license = 'MIT',
    url = 'https://github.com/marmeladema/yara-jsonschema',
    download_url = 'https://github.com/marmeladema/yara-jsonschema/archive/0.1.tar.gz',
    packages = find_packages(),
    long_description = read('README.rst'),
    classifiers = [
        'Development Status :: 3 - Alpha',
        'Intended Audience :: Developers',
        'Topic :: Software Development :: Code Generators',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3',
    ],
    install_requires = [],
    python_requires = '>=3',
    test_suite = 'tests',
    entry_points = {
        'console_scripts': ['yara-jsonschema=yarajsonschema:main'],
    }
)
