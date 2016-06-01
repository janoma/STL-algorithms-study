# Force the strictest warning levels and checks.
# Also, force C++11 in all targets, though it shouldn't really be required.
# Perhaps leave it as a TODO.
add_definitions(-Wall -Werror -Wextra -std=c++11)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(INCLUDE_DIR ../include)

include_directories(${Boost_INCLUDE_DIRS} ${INCLUDE_DIR})

add_executable(test_all_of all_of.cpp)
add_executable(test_for_each for_each.cpp)
add_executable(test_count count.cpp)
add_executable(test_adjacent_find adjacent_find.cpp)
add_executable(test_is_sorted is_sorted.cpp)
add_executable(test_minmax minmax.cpp)

target_link_libraries(test_all_of ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(test_for_each ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(test_count ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(test_adjacent_find ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(test_is_sorted ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(test_minmax ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
