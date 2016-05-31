# Force the strictest warning levels and checks.
# Also, force C++11 in all targets, though it shouldn't really be required.
# Perhaps leave it as a TODO.
add_definitions(-Wall -Werror -Wextra -std=c++11)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(test_all_of all_of.cpp)

target_link_libraries(test_all_of ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
