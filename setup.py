from distutils.core import setup, Extension

modtest = Extension('modtest',
                    sources = ['modtest.c'])

setup (name = 'ModTest',
       version = '1.0',
       description = 'This is a modtest package',
       ext_modules = [modtest])
