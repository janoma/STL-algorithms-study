#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN adjacent_find tests

#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <vector>

#include <operators.h>
#include <point.h>

using point = point_t<int>;

BOOST_TEST_DONT_PRINT_LOG_VALUE(std::vector<point>::const_iterator);

BOOST_AUTO_TEST_SUITE( adjacent_find_test_suite )

BOOST_AUTO_TEST_CASE( empty_container )
{
    const std::vector<point> points;

    auto result = std::adjacent_find(std::begin(points), std::end(points));
    BOOST_CHECK_EQUAL(result, std::end(points));
}

BOOST_AUTO_TEST_CASE( one_element_container )
{
    const std::vector<point> points{{0, 0}};

    auto result = std::adjacent_find(std::begin(points), std::end(points));
    BOOST_CHECK_EQUAL(result, std::end(points));
}

BOOST_AUTO_TEST_CASE( default_compare_end_result )
{
    const points_variety_fixture f;

    auto result = std::adjacent_find(std::begin(f.points), std::end(f.points));
    BOOST_CHECK_EQUAL(result, std::end(f.points));
}

BOOST_AUTO_TEST_CASE( default_compare_middle_result )
{
    const std::vector<point> points{{0, 0}, {5, 0}, {10, 10}, {10, 10}, {20, 4}, {2, 8}};

    auto result = std::adjacent_find(std::begin(points), std::end(points));
    BOOST_REQUIRE_NE(result, std::end(points));
    BOOST_REQUIRE_NE(result, std::prev(std::end(points)));
    BOOST_CHECK_EQUAL(result, std::begin(points) + 2);
    BOOST_CHECK_EQUAL(*result, (point{10, 10}));
}

BOOST_AUTO_TEST_CASE( custom_compare_end_result )
{
    const points_variety_fixture f;

    auto result = std::adjacent_find(std::begin(f.points), std::end(f.points), same_abscissa<points_variety_fixture::coord>);
    BOOST_CHECK_EQUAL(result, std::end(f.points));
}

BOOST_AUTO_TEST_CASE( custom_compare_middle_result )
{
    const points_variety_fixture f;

    auto result = std::adjacent_find(std::begin(f.points), std::end(f.points), same_ordinate<points_variety_fixture::coord>);
    BOOST_REQUIRE_NE(result, std::end(f.points));
    BOOST_REQUIRE_NE(result, std::prev(std::end(f.points)));
    BOOST_CHECK_EQUAL(result, std::begin(f.points));
    BOOST_CHECK_EQUAL(*result, (point{0, 0}));
}

BOOST_AUTO_TEST_CASE( implicit_conversion_compare_middle_result )
{
    const points_variety_fixture f;

    auto result = std::adjacent_find(std::begin(f.points), std::end(f.points), same_area<points_variety_fixture::coord>);
    BOOST_REQUIRE_NE(result, std::end(f.points));
    BOOST_REQUIRE_NE(result, std::prev(std::end(f.points)));
    BOOST_CHECK_EQUAL(result, std::begin(f.points));
    BOOST_CHECK_EQUAL(*result, (point{0, 0}));
}

BOOST_AUTO_TEST_CASE( true_no_op_begin_result )
{
    const points_variety_fixture f;

    /*! Trivial case: if the predicate always returns true, adjacent_find
     * returns the first element. */
    auto result = std::adjacent_find(std::begin(f.points), std::end(f.points), true_no_op());
    BOOST_CHECK_EQUAL(result, std::begin(f.points));
}

BOOST_AUTO_TEST_CASE( false_no_op_begin_result )
{
    const points_variety_fixture f;

    /*! Trivial case: if the predicate always returns false, adjacent_find
     * returns the past-the-end iterator. */
    auto result = std::adjacent_find(std::begin(f.points), std::end(f.points), false_no_op());
    BOOST_CHECK_EQUAL(result, std::end(f.points));
}

BOOST_AUTO_TEST_SUITE_END( /* adjacent_find_test_suite */ )
