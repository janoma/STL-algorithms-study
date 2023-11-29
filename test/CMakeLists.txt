# Force the strictest warning levels and checks.
# Also, force C++11 in all targets, though it shouldn't really be required.
# Perhaps leave it as a TODO.
add_definitions(-Wall -Werror -Wextra -std=c++11)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIR})
  message("-- Boost found: ${Boost_VERSION_STRING}")
else()
  message(FATAL_ERROR "Boost not found!")
endif()

set(INCLUDE_DIR ../include)

include_directories(${Boost_INCLUDE_DIRS} ${INCLUDE_DIR})

# Non-modifying sequence operations
add_executable(test_all_of all_of.cpp)
add_executable(test_for_each for_each.cpp)
add_executable(test_count count.cpp)
add_executable(test_equal equal.cpp)
add_executable(test_adjacent_find adjacent_find.cpp)

# Modifying sequence operations

# Partitioning operations
add_executable(test_partition partition.cpp)

# Sorting operations (on sorted ranges)
add_executable(test_is_sorted is_sorted.cpp)

# Binary search operations (on sorted ranges)

# Set operations (on sorted ranges)
add_executable(test_set_difference set_difference.cpp)
add_executable(test_set_intersection set_intersection.cpp)
add_executable(test_set_symmetric_difference set_symmetric_difference.cpp)
add_executable(test_set_union set_union.cpp)

# Heap operations

# Mimimum/maximum operations
add_executable(test_minmax minmax.cpp)

# Non-modifying sequence operations
target_link_libraries(test_all_of ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(test_for_each ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(test_count ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(test_equal ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(test_adjacent_find ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

# Modifying sequence operations

# Partitioning operations
target_link_libraries(test_partition ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

# Sorting operations (on sorted ranges)
target_link_libraries(test_is_sorted ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

# Binary search operations (on sorted ranges)

# Set operations (on sorted ranges)
target_link_libraries(test_set_difference ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(test_set_intersection ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(test_set_symmetric_difference ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(test_set_union ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

# Heap operations

# Mimimum/maximum operations
target_link_libraries(test_minmax ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
