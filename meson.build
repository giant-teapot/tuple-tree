project('tuple-tree', 
    'cpp',
    version : '0.0.1',
    license : 'ISC'
)

tupletree_dep = declare_dependency(
    include_directories : include_directories('include')
)

#-------------------------------------------------------------------------------
catch2 = subproject('catch2')
catch2_dep = catch2.get_variable('catch2_dep')
#-------------------------------------------------------------------------------

test_src = ['test/test.cpp']
unit_tests = executable(
    'unit-tests',
    test_src,
    dependencies: [tupletree_dep, catch2_dep]
)
test('tuple-tree unit tests', unit_tests)