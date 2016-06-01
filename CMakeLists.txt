# Not really necessary yet, but it might be if target_compile_features are used.
# cmake_minimum_required(VERSION 3.1)

project(stl_algorithm_tests)

add_subdirectory(test)

enable_testing()

add_test(NAME all_of COMMAND test_all_of)
add_test(NAME count COMMAND test_count)
add_test(NAME is_sorted COMMAND test_is_sorted)
add_test(NAME minmax COMMAND test_minmax)
