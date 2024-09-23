project(
  'integer_toolkit', 'c',
  version: '0.1.0',
  default_options: ['warning_level=3'],
  license: 'MIT',
  license_files: 'LICENSE'
)

incdir = include_directories('include')

library('integer_toolkit', 'src/integer_toolkit.c',
  include_directories: incdir,
  install: true,
  install_dir: 'lib'
)

install_headers('include/integer_toolkit.h', subdir: 'integer_toolkit')