#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN set_intersection tests

#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <list>
#include <vector>

BOOST_AUTO_TEST_SUITE( set_intersection_test_suite )

BOOST_AUTO_TEST_CASE( empty_primary_input_default_compare )
{
    const std::vector<int> primary;
    const std::list<int> secondary{1, 2, 3};
    std::vector<int> output;

    std::set_intersection(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output));

    const std::vector<int> expected;
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( empty_primary_input_custom_compare )
{
    const std::vector<int> primary;
    const std::list<int> secondary{3, 2, 1};
    std::vector<int> output;

    std::set_intersection(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output), std::greater<int>());

    const std::vector<int> expected;
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( empty_primary_input_conversion_compare )
{
    const std::vector<int> primary;
    const std::list<int> secondary{1, 2, 3};
    std::vector<int> output;

    std::set_intersection(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output), std::less<double>());

    const std::vector<int> expected;
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( same_type_inputs_default_compare )
{
    const std::vector<int> primary{1, 3, 4, 5, 6};
    const std::list<int> secondary{1, 2, 3};
    std::vector<int> output;

    std::set_intersection(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output));

    const std::vector<int> expected{1, 3};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( same_type_inputs_custom_compare )
{
    const std::vector<int> primary{1, -3, -4, 5, -6};
    const std::list<int> secondary{1, -2, 3};
    std::vector<int> output;

    auto comp = [](int lhs, int rhs){ return std::less<int>()(std::abs(lhs), std::abs(rhs)); };
    std::set_intersection(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output), comp);

    const std::vector<int> expected{1, -3};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( same_type_inputs_conversion_compare )
{
    const std::vector<int> primary{1, -3, -4, 5, -6};
    const std::list<int> secondary{1, -2, 3};
    std::vector<int> output;

    auto comp = [](double lhs, double rhs){ return std::less<double>()(std::abs(lhs), std::abs(rhs)); };
    std::set_intersection(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output), comp);

    const std::vector<int> expected{1, -3};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( different_type_inputs_default_compare )
{
    const std::vector<int> primary{1, 3, 4, 5, 6};
    const std::list<double> secondary{1.1, 2, 4.0, 4.6};
    std::vector<int> output;

    /*! For the default compare between an int and a double, the int will be
     * promoted to double first, so for example 1 will be considered different
     * to 1.1, in which case none of them will be reported to the output
     * iterator. */
    std::set_intersection(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output));

    const std::vector<int> expected{4};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( different_type_inputs_custom_compare )
{
    const std::vector<int> primary{1, 3, 4, 5, 6};
    const std::list<double> secondary{1.1, 2, 3.9, 4.6};
    std::vector<int> output;

    auto comp = [](int lhs, double rhs){ return std::less<double>()(static_cast<double>(lhs), std::floor(rhs)); };
    std::set_intersection(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output), comp);

    const std::vector<int> expected{1, 3, 4};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( repeated_elements_default_compare )
{
    const std::vector<int> primary{1, 1, 1, 1, 2, 3, 3, 3, 3, 4, 4, 5, 6};
    const std::list<int> secondary{1, 1, 2, 3};
    std::vector<int> output;

    std::set_intersection(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output));

    const std::vector<int> expected{1, 1, 2, 3};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( different_output_type_default_compare )
{
    const std::vector<double> primary{1, 3, 4.6, 5, 6};
    const std::list<double> secondary{1.1, 2, 3.9, 4.6};
    std::vector<int> output;

    std::set_intersection(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output));

    const std::vector<int> expected{4};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( different_output_type_custom_compare )
{
    const std::vector<double> primary{-1.1, 1, -1, 3, 4.6, 5, 6};
    const std::list<double> secondary{1.1, -2, 3.9, -4.6};
    std::vector<int> output;

    auto comp = [](double lhs, double rhs){ return std::less<double>()(std::abs(lhs), std::abs(rhs)); };
    std::set_intersection(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output), comp);

    /*! Here is the interesting thing: -1.1 will be compared equal to 1.1 and
     * reported to an output iterator that accepts ints. As the algorithm
     * reports the element from the first collection, -1.1 will be cast to int,
     * so the number in the output collection will be negative as well. */
    const std::vector<int> expected{-1, 4};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_SUITE_END( /* set_intersection_test_suite */ )
