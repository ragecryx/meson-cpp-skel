project('skeleton', 'cpp', default_options : ['c_std=c11', 'cpp_std=c++11'])

if get_option('buildtype').startswith('debug')
  add_project_arguments('-DDEBUG', language : 'cpp')
endif



# === EXT ============
thread_dep = dependency('threads')

gtest = subproject('gtest')
gtest_dep = gtest.get_variable('gtest_dep')



# === LIBRARY ============
lib_inc = include_directories('lib/include')

# Define platform specific source files
if target_machine.system() == 'windows'
    lib_platform_src = [
        'lib/src/Platforms/win32/LibraryExtra.cpp',
    ]

    lib_platform_dep = [
    ]
elif target_machine.system() == 'linux'
    lib_platform_src = [
        'lib/src/Platforms/linux/LibraryExtra.cpp',
    ]

    lib_platform_dep = [
    ]
endif

# Define common source files + platform specific
lib_src = [
    'lib/src/Library.cpp',

    lib_platform_src
]

# Common dependencies
lib_common_dep = [thread_dep]

# Choose whether to build a shared or static library
if get_option('shared_library')
    libTestLib = shared_library(
        'testlib',
        lib_src,
        dependencies: [lib_common_dep, lib_platform_dep],
        version: '0.0.1', soversion: '0',
        include_directories: lib_inc,
        install: true
    )
else
    libTestLib = static_library(
        'testlib',
        lib_src,
        dependencies: [lib_common_dep, lib_platform_dep],
        include_directories: lib_inc,
        install: true
    )
endif

libTestLib_dep = declare_dependency(include_directories: lib_inc, link_with: libTestLib, dependencies: lib_common_dep)

# === TESTS ============
tests_src = [
    'lib/tests/Test_TestClass.cpp',
    'lib/tests/main.cpp',
]

executable('libTestLib_tests', tests_src, dependencies: [libTestLib_dep, gtest_dep])



# === MAIN APP ============
main_src = [
    'src/main.cpp',
]

executable('TestExecutable', main_src, dependencies: [libTestLib_dep])
