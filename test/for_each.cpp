#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN for_each tests

#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <functional>
#include <vector>

#include <point.h>

BOOST_AUTO_TEST_SUITE( for_each_test_suite )

BOOST_AUTO_TEST_CASE( sum_each_number )
{
    std::vector<int> numbers{1, 2, 3};
    auto f = [](int& n) { ++n; };

    std::for_each(std::begin(numbers), std::end(numbers), f);

    const std::vector<int> expected{2, 3, 4};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(numbers), std::end(numbers), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( sum_each_number_twice )
{
    std::vector<int> numbers{1, 2, 3};

    /*! As std::for_each returns the function, we can use it as a lambda and
     * then apply it again, so the numbers will be increased twice. Of course
     * this particular scenario can also be achieved by adding 2 to each number,
     * but other uses can include calling the same lambda on different
     * collections. */
    std::for_each(std::begin(numbers), std::end(numbers),
            std::for_each(std::begin(numbers), std::end(numbers), [](int& n){ ++n; })
    );

    const std::vector<int> expected{3, 4, 5};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(numbers), std::end(numbers), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( accumulate_total )
{
    std::vector<int> numbers;
    for (std::size_t i = 1; i <= 1000; ++i)
    {
        numbers.push_back(i);
    }

    int total = 0;
    auto f = [&total](int n) { total += n; };

    /*! Yes, this can be done with std::accumulate. */
    std::for_each(std::begin(numbers), std::end(numbers), f);

    /*! If you don't know this formula, review your discrete math or calculus
     * notes. Or google it. */
    int expected = 1000 * 1001 / 2;
    BOOST_CHECK_EQUAL(total, expected);
}

BOOST_AUTO_TEST_CASE( implicit_conversion_by_copy )
{
    using coord = int;
    using point = point_t<coord>;
    using rectangle = rectangle_t<coord>;
    const std::vector<point> points{{1, 2}, {-5, 3}, {4, 7}};

    coord total_area = 0;
    /*! This function takes a rectangle as parameter. The points in the
     * collection are implicitly converted to rectangle */
    auto area_accumulator = [&total_area](rectangle const& rect)
    {
        total_area += area(rect);
    };

    /*! Pass the function by copy. */
    std::for_each(std::begin(points), std::end(points), area_accumulator);

    coord expected_area = 1 * 2 + 5 * 3 + 4 * 7;
    BOOST_CHECK_EQUAL(total_area, expected_area);
}

BOOST_AUTO_TEST_CASE( implicit_conversion_by_reference )
{
    using point = point_t<int>;
    using rectangle = rectangle_t<int>;
    const std::vector<point> points{{1, 2}, {-5, 3}, {4, 7}};

    struct area_accumulator
    {
        area_accumulator()
            : total_area(0)
        {
        }

        inline void
        operator()(rectangle const& rect) const
        {
            total_area += area(rect);
        }

        mutable int total_area;
    };

    area_accumulator accumulator;

    /*! Pass the function by reference. */
    std::for_each(std::begin(points), std::end(points), std::ref(accumulator));

    int expected_area = 1 * 2 + 5 * 3 + 4 * 7;
    BOOST_CHECK_EQUAL(accumulator.total_area, expected_area);

    /*! Note how passing the accumulator by copy should give a
     * default-constructed value for the total area, which is zero. */
    area_accumulator another_accumulator;
    std::for_each(std::begin(points), std::end(points), another_accumulator);
    BOOST_CHECK_EQUAL(another_accumulator.total_area, 0);
}

BOOST_AUTO_TEST_SUITE_END( /* for_each_test_suite */ )
