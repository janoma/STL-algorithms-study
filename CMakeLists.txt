# Not really necessary yet, but it might be if target_compile_features are used.
# cmake_minimum_required(VERSION 3.1)

project(stl_algorithm_tests)

add_subdirectory(test)

enable_testing()

add_test(NAME all_of COMMAND test_all_of)
add_test(NAME for_each COMMAND test_for_each)
add_test(NAME count COMMAND test_count)
add_test(NAME equal COMMAND test_equal)
add_test(NAME adjacent_find COMMAND test_adjacent_find)
add_test(NAME is_sorted COMMAND test_is_sorted)
add_test(NAME minmax COMMAND test_minmax)
