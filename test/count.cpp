#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN count count_if tests

#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <vector>

#include "operators.h"
#include "rectangle.h"

using rectangle = rectangle_t<int>;

BOOST_AUTO_TEST_SUITE( count_test_suite )

BOOST_AUTO_TEST_CASE( empty_container_count )
{
    std::vector<rectangle> rects;
    rectangle target;

    /*! True regardless of the coordinates of the 'target' rectangle, which
     * *actually contains garbage*. */
    BOOST_CHECK_EQUAL(std::count(std::begin(rects), std::end(rects), target), 0);
    BOOST_CHECK_EQUAL(std::count(std::begin(rects), std::end(rects), target), 0);
}

BOOST_AUTO_TEST_CASE( empty_container_count_if )
{
    std::vector<rectangle> rects;

    BOOST_CHECK_EQUAL(std::count_if(std::begin(rects), std::end(rects), true_no_op()), 0);
    BOOST_CHECK_EQUAL(std::count_if(std::begin(rects), std::end(rects), false_no_op()), 0);
    BOOST_CHECK_EQUAL(std::count_if(std::begin(rects), std::end(rects), alternating_no_op()), 0);
}

BOOST_AUTO_TEST_CASE( count_zero )
{
    positive_area_rects_fixture f;

    BOOST_CHECK_EQUAL(std::count(std::begin(f.rects), std::end(f.rects), rectangle{1, 2, 3, 4}), 0);
    BOOST_CHECK_EQUAL(std::count(std::begin(f.rects), std::end(f.rects), rectangle{0, 0, 0, 0}), 0);
    BOOST_CHECK_EQUAL(std::count(std::begin(f.rects), std::end(f.rects), rectangle{0, 0, 10, 10}), 0);
}

BOOST_AUTO_TEST_CASE( count_one )
{
    positive_area_rects_fixture f;

    BOOST_CHECK_EQUAL(std::count(std::begin(f.rects), std::end(f.rects), rectangle{10, 0, 50, 10}), 1);
    BOOST_CHECK_EQUAL(std::count(std::begin(f.rects), std::end(f.rects), rectangle{20, 30, 50, 40}), 1);
    BOOST_CHECK_EQUAL(std::count(std::begin(f.rects), std::end(f.rects), f.rects.front()), 1);
}

BOOST_AUTO_TEST_CASE( count_many )
{
    positive_area_rects_fixture f;

    BOOST_CHECK_EQUAL(std::count(std::begin(f.rects), std::end(f.rects), rectangle{0, 0, 1, 1}), 4);
}

BOOST_AUTO_TEST_SUITE_END( /* count_test_suite */ )
