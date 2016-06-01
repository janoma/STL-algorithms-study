#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN minmax tests

#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <initializer_list>
#include <vector>

#include <point.h>

using point = point_t<int>;

BOOST_AUTO_TEST_SUITE( minmax_test_suite )

BOOST_AUTO_TEST_CASE( binary_min_default_compare )
{
    const point p1{0, 0};
    const point p2{10, 20};
    BOOST_CHECK_EQUAL(std::min(p1, p2), p1);
    BOOST_CHECK_EQUAL(std::min(p2, p1), p1);
    BOOST_CHECK_EQUAL(std::min(p1, p2), (point{0, 0}));
}

BOOST_AUTO_TEST_CASE( binary_min_custom_compare )
{
    const point p1{0, 0};
    const point p2{0, 20};
    BOOST_CHECK_EQUAL(std::min(p1, p2, raster_by_x()), p2);
    BOOST_CHECK_EQUAL(std::min(p2, p1, raster_by_x()), p2);
    BOOST_CHECK_EQUAL(std::min(p1, p2, raster_by_x()), (point{0, 20}));
}

BOOST_AUTO_TEST_CASE( binary_min_conversion_compare )
{
    const point p1{-10, -10};
    const point p2{5, 5};
    /*! p1 is smaller in the default, raster order, but has larger area after
     * the implicit conversion to rectangle. */
    BOOST_CHECK_EQUAL(std::min(p1, p2, compare_by_area<int>()), p2);
}

BOOST_AUTO_TEST_CASE( binary_max_default_compare )
{
    const point p1{0, 0};
    const point p2{10, 20};
    BOOST_CHECK_EQUAL(std::max(p1, p2), p2);
    BOOST_CHECK_EQUAL(std::max(p2, p1), p2);
    BOOST_CHECK_EQUAL(std::max(p1, p2), (point{10, 20})); /*! most vexing parse, but there you are */
}

BOOST_AUTO_TEST_CASE( binary_max_custom_compare )
{
    const point p1{0, 0};
    const point p2{0, 20};
    BOOST_CHECK_EQUAL(std::max(p1, p2, raster_by_x()), p1);
    BOOST_CHECK_EQUAL(std::max(p2, p1, raster_by_x()), p1);
    BOOST_CHECK_EQUAL(std::max(p1, p2, raster_by_x()), (point{0, 0}));
}

BOOST_AUTO_TEST_CASE( binary_max_conversion_compare )
{
    const point p1{-10, -10};
    const point p2{5, 5};
    BOOST_CHECK_EQUAL(std::max(p1, p2, compare_by_area<int>()), p1);
}

BOOST_AUTO_TEST_CASE( n_ary_min_default_compare )
{
    std::initializer_list<point> points{{0, 0}, {50, 50}, {20, 10}, {100, 100}, {15, 50}};
    const point target{0, 0};

    BOOST_CHECK_EQUAL(std::min(points), target);
}

BOOST_AUTO_TEST_CASE( n_ary_min_custom_compare )
{
    std::initializer_list<point> points{{0, 0}, {50, 50}, {20, 10}, {100, 100}, {15, 50}};
    const point target{0, 0};

    BOOST_CHECK_EQUAL(std::min(points, raster_by_x()), target);
}

BOOST_AUTO_TEST_CASE( n_ary_min_conversion_compare )
{
    std::initializer_list<point> points{{0, 0}, {50, 50}, {20, 10}, {100, 100}, {15, 50}};
    const point target{0, 0};

    BOOST_CHECK_EQUAL(std::min(points, compare_by_area<int>()), target);
}

BOOST_AUTO_TEST_CASE( n_ary_max_default_compare )
{
    std::initializer_list<point> points{{0, 0}, {50, 50}, {20, 10}, {100, 100}, {15, 50}};
    const point target{100, 100};

    BOOST_CHECK_EQUAL(std::max(points), target);
}

BOOST_AUTO_TEST_CASE( n_ary_max_custom_compare )
{
    std::initializer_list<point> points{{0, 0}, {50, 50}, {20, 10}, {100, 100}, {15, 50}};
    const point target{100, 100};

    BOOST_CHECK_EQUAL(std::max(points, raster_by_x()), target);
}

BOOST_AUTO_TEST_CASE( n_ary_max_conversion_compare )
{
    std::initializer_list<point> points{{0, 0}, {50, 50}, {20, 10}, {100, 100}, {15, 50}};
    const point target{100, 100};

    BOOST_CHECK_EQUAL(std::max(points, compare_by_area<int>()), target);
}

BOOST_AUTO_TEST_CASE( min_element_default_compare )
{
    points_variety_fixture f;
    const point target{0, 0};

    BOOST_CHECK_EQUAL(*std::min_element(std::begin(f.points), std::end(f.points)), target);
}

BOOST_AUTO_TEST_CASE( min_element_custom_compare )
{
    points_variety_fixture f;
    const point target{0, 5};

    BOOST_CHECK_EQUAL(*std::min_element(std::begin(f.points), std::end(f.points), raster_by_x()), target);
}

BOOST_AUTO_TEST_CASE( min_element_conversion_compare )
{
    points_variety_fixture f;
    const point target{0, 0};

    BOOST_CHECK_EQUAL(*std::min_element(std::begin(f.points), std::end(f.points), compare_by_area<int>()), target);
}

BOOST_AUTO_TEST_CASE( max_element_default_compare )
{
    points_variety_fixture f;
    const point target{100, 100};

    BOOST_CHECK_EQUAL(*std::max_element(std::begin(f.points), std::end(f.points)), target);
}

BOOST_AUTO_TEST_CASE( max_element_custom_compare )
{
    points_variety_fixture f;
    const point target{100, 100};

    BOOST_CHECK_EQUAL(*std::max_element(std::begin(f.points), std::end(f.points), raster_by_x()), target);
}

BOOST_AUTO_TEST_CASE( max_element_conversion_compare )
{
    points_variety_fixture f;
    const point target{100, 100};

    BOOST_CHECK_EQUAL(*std::max_element(std::begin(f.points), std::end(f.points), compare_by_area<int>()), target);
}

BOOST_AUTO_TEST_CASE( binary_minmax_default_compare )
{
    const point p1{0, 0};
    const point p2{0, 20};

    auto minmax = std::minmax(p1, p2);

    BOOST_CHECK_EQUAL(minmax.first, p1);
    BOOST_CHECK_EQUAL(minmax.second, p2);
}

BOOST_AUTO_TEST_CASE( binary_minmax_custom_compare )
{
    const point p1{0, 0};
    const point p2{0, 20};

    auto minmax = std::minmax(p1, p2, raster_by_x());

    BOOST_CHECK_EQUAL(minmax.first, p2);
    BOOST_CHECK_EQUAL(minmax.second, p1);
}

BOOST_AUTO_TEST_CASE( binary_minmax_conversion_compare )
{
    const point p1{0, 0};
    const point p2{0, 20};

    auto minmax = std::minmax(p1, p2, compare_by_area<int>());

    BOOST_CHECK_EQUAL(minmax.first, p1);
    BOOST_CHECK_EQUAL(minmax.second, p2);
}

BOOST_AUTO_TEST_CASE( n_ary_minmax_default_compare )
{
    std::initializer_list<point> points{{0, 0}, {50, 50}, {20, 10}, {100, 100}, {15, 50}, {100, 90}, {0, 5}};
    const point min{0, 0};
    const point max{100, 100};

    auto minmax = std::minmax(points);

    BOOST_CHECK_EQUAL(minmax.first, min);
    BOOST_CHECK_EQUAL(minmax.second, max);
}

BOOST_AUTO_TEST_CASE( n_ary_minmax_custom_compare )
{
    std::initializer_list<point> points{{0, 0}, {50, 50}, {20, 10}, {100, 100}, {15, 50}, {100, 90}, {0, 5}};
    const point min{0, 5};
    const point max{100, 90};

    auto minmax = std::minmax(points, raster_by_x());

    BOOST_CHECK_EQUAL(minmax.first, min);
    BOOST_CHECK_EQUAL(minmax.second, max);
}

BOOST_AUTO_TEST_CASE( n_ary_minmax_conversion_compare )
{
    std::initializer_list<point> points{{0, 0}, {50, 50}, {20, 10}, {100, 100}, {15, 50}, {100, 90}, {0, 5}};
    const point min{0, 0};
    const point max{100, 100};

    auto minmax = std::minmax(points, compare_by_area<int>());

    BOOST_CHECK_EQUAL(minmax.first, min);
    BOOST_CHECK_EQUAL(minmax.second, max);
}

BOOST_AUTO_TEST_CASE( minmax_element_default_compare )
{
    points_variety_fixture f;
    const point min_target{0, 0};
    const point max_target{100, 100};

    auto minmax = std::minmax_element(std::begin(f.points), std::end(f.points));

    BOOST_CHECK_EQUAL(*minmax.first, min_target);
    BOOST_CHECK_EQUAL(*minmax.second, max_target);
}

BOOST_AUTO_TEST_CASE( minmax_element_custom_compare )
{
    points_variety_fixture f;
    const point min_target{0, 5};
    const point max_target{100, 100};

    auto minmax = std::minmax_element(std::begin(f.points), std::end(f.points), raster_by_x());

    BOOST_CHECK_EQUAL(*minmax.first, min_target);
    BOOST_CHECK_EQUAL(*minmax.second, max_target);
}

BOOST_AUTO_TEST_CASE( minmax_element_conversion_compare )
{
    points_variety_fixture f;
    const point min_target{0, 0};
    const point max_target{100, 100};

    auto minmax = std::minmax_element(std::begin(f.points), std::end(f.points), compare_by_area<int>());

    BOOST_CHECK_EQUAL(*minmax.first, min_target);
    BOOST_CHECK_EQUAL(*minmax.second, max_target);
}

BOOST_AUTO_TEST_SUITE_END( /* minmax_test_suite */ )
