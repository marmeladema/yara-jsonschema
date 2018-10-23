===============
yara-jsonschema
===============

.. image:: https://travis-ci.com/marmeladema/yara-jsonschema.svg?branch=master
    :target: https://travis-ci.com/marmeladema/yara-jsonschema

---------------

:Author: `Elie ROUDNINSKI <mailto:xademax@gmail.com>`_

**yara-jsonschema** is a pure Python package that tries to generate YARA module object C code based on a json-schema description.
It provides both a **yarajsonschema** Python module and **yara-jsonschema** binary.

Generated code uses Jansson library to manipulate JSON and populate the YARA module object.

Installation
============

Requirements
------------

**yara-jsonschema** requires Python 3. It has been tested on Python 3.5 and 3.6 under Linux.

From github
-----------

You can clone this repository and install it with setuptools directly::

    $ python3 setup.py install --user

Tests
-----

Tests are available in the source distribution (either from github or from pip) and are located in the |tests/|_ directory.
You can run them with setuptools::

    $ python3 setup.py test

.. |tests/| replace:: ``tests/``
.. _tests/: tests/


Usage
=====

Classic usage is just executing the **yara-jsonschema** binary with a json-schema as argument:

    $ yara-jsonschema examples/har/pageTimings.json --dec-output examples/har/pageTimings-dec.h --set-output examples/har/pageTimings-set.h

It will generates:

- A declaration header: |examples/har/pageTimings-dec.h|_

.. |examples/har/pageTimings-dec.h| replace:: ``examples/har/pageTimings-dec.h``
.. _examples/har/pageTimings-dec.h: examples/har/pageTimings-dec.h

- An assigment header: |examples/har/pageTimings-set.h|_

.. |examples/har/pageTimings-set.h| replace:: ``examples/har/pageTimings-set.h``
.. _examples/har/pageTimings-set.h: examples/har/pageTimings-set.h


TODO
====

- Supports combination keywords: allOf, anyOf, oneOf, not
