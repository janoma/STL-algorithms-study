# Not really necessary yet, but it might be if target_compile_features are used.
# cmake_minimum_required(VERSION 3.1)

project(stl_algorithm_tests)

add_subdirectory(test)

enable_testing()

add_test(NAME all_of COMMAND test_all_of)

