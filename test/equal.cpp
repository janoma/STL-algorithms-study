#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN equal tests

#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <cmath>
#include <list>
#include <vector>

#include <operators.h>

BOOST_AUTO_TEST_SUITE( equal_test_suite )

BOOST_AUTO_TEST_CASE( empty_containers_default_compare )
{
    std::vector<int> numbers_vector;
    std::list<int> numbers_list;

    BOOST_CHECK(std::equal(std::begin(numbers_vector), std::end(numbers_vector), std::begin(numbers_list)));
}

BOOST_AUTO_TEST_CASE( empty_containers_different_types_default_compare )
{
    std::vector<int> numbers_vector;
    std::list<double> numbers_list;

    /*! It works as expected, as the types are implicitly convertible between
     * them. */
    BOOST_CHECK(std::equal(std::begin(numbers_vector), std::end(numbers_vector), std::begin(numbers_list)));
}

BOOST_AUTO_TEST_CASE( empty_containers_different_types_viceversa_default_compare )
{
    std::vector<int> numbers_vector;
    std::list<double> numbers_list;

    /*! It works as expected, as the types are implicitly convertible between
     * them. */
    BOOST_CHECK(std::equal(std::begin(numbers_list), std::end(numbers_list), std::begin(numbers_vector)));
}

BOOST_AUTO_TEST_CASE( empty_containers_custom_compare )
{
    std::vector<int> numbers_vector;
    std::list<int> numbers_list;

    BOOST_CHECK(std::equal(std::begin(numbers_vector), std::end(numbers_vector), std::begin(numbers_list), alternating_no_op()));
    BOOST_CHECK(std::equal(std::begin(numbers_vector), std::end(numbers_vector), std::begin(numbers_list), true_no_op()));
    BOOST_CHECK(std::equal(std::begin(numbers_vector), std::end(numbers_vector), std::begin(numbers_list), false_no_op()));
}

BOOST_AUTO_TEST_CASE( empty_and_nonempty_container_default_compare )
{
    std::vector<int> numbers_vector;
    std::list<int> numbers_list{3, 4, 5};

    BOOST_CHECK(std::equal(std::begin(numbers_vector), std::end(numbers_vector), std::begin(numbers_list)));
}

BOOST_AUTO_TEST_CASE( nonempty_containers_same_type_default_compare )
{
    const std::vector<int> numbers1{1, 2, -4, 9, -9};

    /*! Not necessary to have the same number of elements, as numbers2 will be
     * traversed only until its 5th element, because numbers1 contains 5
     * elements. */
    const std::vector<int> numbers2{1, 2, -4, 9, -9, 10, 11};

    BOOST_CHECK(std::equal(std::begin(numbers1), std::end(numbers1), std::begin(numbers2)));
}

BOOST_AUTO_TEST_CASE( nonempty_containers_same_type_custom_compare )
{
    const std::vector<int> numbers1{1, 2, -4, 9, -9};
    const std::vector<int> numbers2{-1, -2, -4, -9, 9};

    BOOST_CHECK(std::equal(std::begin(numbers1), std::end(numbers1), std::begin(numbers2), [](int lhs, int rhs)
    {
        return std::equal_to<int>()(std::abs(lhs), std::abs(rhs));
    }));
}

BOOST_AUTO_TEST_CASE( nonempty_containers_different_types_custom_compare )
{
    const std::vector<int> numbers_vector{1, 2, -4, 9, -9};
    const std::list<double> numbers_list{1.0, 2.1, -3.001, 9.999, -9.0};

    BOOST_CHECK(std::equal(std::begin(numbers_vector), std::end(numbers_vector), std::begin(numbers_list), [](int n, double d)
    {
        return static_cast<double>(n) == std::floor(d);
    }));
}

BOOST_AUTO_TEST_SUITE_END( /* equal_test_suite */ )
