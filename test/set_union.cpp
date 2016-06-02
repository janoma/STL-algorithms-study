#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN set_union tests

#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <list>
#include <vector>

BOOST_AUTO_TEST_SUITE( set_union_test_suite )

BOOST_AUTO_TEST_CASE( empty_primary_input_default_compare )
{
    const std::vector<int> primary;
    const std::list<int> secondary{1, 2, 3};
    std::vector<int> output;

    std::set_union(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output));

    const std::vector<int> expected{1, 2, 3};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( empty_primary_input_custom_compare )
{
    const std::vector<int> primary;
    const std::list<int> secondary{3, 2, 1};
    std::vector<int> output;

    std::set_union(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output), std::greater<int>());

    const std::vector<int> expected{3, 2, 1};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( empty_primary_input_conversion_compare )
{
    const std::vector<int> primary;
    const std::list<int> secondary{1, 2, 3};
    std::vector<int> output;

    std::set_union(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output), std::less<double>());

    const std::vector<int> expected{1, 2, 3};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( same_type_inputs_default_compare )
{
    const std::vector<int> primary{1, 3, 4, 5, 6};
    const std::list<int> secondary{1, 2, 3};
    std::vector<int> output;

    std::set_union(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output));

    const std::vector<int> expected{1, 2, 3, 4, 5, 6};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( same_type_inputs_custom_compare )
{
    const std::vector<int> primary{1, -3, -4, 5, -6};
    const std::list<int> secondary{1, -2, 3};
    std::vector<int> output;

    auto comp = [](int lhs, int rhs){ return std::less<int>()(std::abs(lhs), std::abs(rhs)); };
    std::set_union(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output), comp);

    const std::vector<int> expected{1, -2, -3, -4, 5, -6};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( same_type_inputs_conversion_compare )
{
    const std::vector<int> primary{1, -3, -4, 5, -6};
    const std::list<int> secondary{1, -2, 3};
    std::vector<int> output;

    auto comp = [](double lhs, double rhs){ return std::less<double>()(std::abs(lhs), std::abs(rhs)); };
    std::set_union(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output), comp);

    const std::vector<int> expected{1, -2, -3, -4, 5, -6};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( different_type_inputs_default_compare )
{
    const std::vector<int> primary{1, 3, 4, 5, 6};
    const std::list<double> secondary{1.1, 2, 4.0, 4.6};
    std::vector<int> output;

    /*! For the default compare between an int and a double, the int will be
     * promoted to double first, so for example 1 will be considered different
     * to 1.1, in which case 1.1 will be reported to the output iterator. As the
     * output iterator receives ints, the value 1.1 will be implicitly cast to
     * int, which means a second "1" will appear in the output collection.
     * Similarly, 4 will be considered equal to 4.0 but different to 4.6, and
     * two "4" values will be reported. */
    std::set_union(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output));

    const std::vector<int> expected{1, 1, 2, 3, 4, 4, 5, 6};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( different_type_inputs_custom_compare )
{
    const std::vector<int> primary{1, 3, 4, 5, 6};
    const std::list<double> secondary{1.1, 2, 3.9, 4.6};
    std::vector<int> output;

    auto comp = [](int lhs, double rhs){ return std::less<double>()(static_cast<double>(lhs), std::floor(rhs)); };
    std::set_union(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output), comp);

    const std::vector<int> expected{1, 2, 3, 4, 5, 6};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( repeated_elements_default_compare )
{
    const std::vector<int> primary{1, 1, 1, 1, 2, 3, 3, 3, 3, 4, 4, 5, 6};
    const std::list<int> secondary{1, 1, 2, 3};
    std::vector<int> output;

    std::set_union(std::begin(primary), std::end(primary), std::begin(secondary), std::end(secondary), std::back_inserter(output));

    const std::vector<int> expected{1, 1, 1, 1, 2, 3, 3, 3, 3, 4, 4, 5, 6};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(output), std::end(output), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_SUITE_END( /* set_union_test_suite */ )
