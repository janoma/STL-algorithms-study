#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN is_sorted tests

#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <functional>
#include <vector>

BOOST_TEST_DONT_PRINT_LOG_VALUE(std::vector<int>::const_iterator);

BOOST_AUTO_TEST_SUITE( is_sorted_test_suite )

BOOST_AUTO_TEST_CASE( int_collection_sorted_default_compare_sorted )
{
    const std::vector<int> numbers{1, 2, 3, 3, 3, 4, 5, 6, 6, 7};

    BOOST_CHECK(std::is_sorted(std::begin(numbers), std::end(numbers)));
}

BOOST_AUTO_TEST_CASE( int_collection_sorted_default_compare_not_sorted )
{
    const std::vector<int> numbers{1, 2, 3, 3, 3, 4, 5, 6, 6, 7, 6};

    BOOST_CHECK(not std::is_sorted(std::begin(numbers), std::end(numbers)));
}

BOOST_AUTO_TEST_CASE( int_collection_sorted_custom_compare_sorted )
{
    const std::vector<int> numbers{7, 6, 6, 5, 4, 3, 3, 3, 2, 1};

    BOOST_CHECK(std::is_sorted(std::begin(numbers), std::end(numbers), std::greater<int>()));
}

BOOST_AUTO_TEST_CASE( int_collection_sorted_custom_compare_not_sorted )
{
    const std::vector<int> numbers{7, 6, 6, 5, 4, 3, 3, 3, 2, 1, 2, 1, 0};

    BOOST_CHECK(not std::is_sorted(std::begin(numbers), std::end(numbers), std::greater<int>()));
}

BOOST_AUTO_TEST_CASE( int_collection_sorted_until_default_compare_sorted )
{
    const std::vector<int> numbers{1, 2, 3, 4};

    BOOST_CHECK_EQUAL(std::is_sorted_until(std::begin(numbers), std::end(numbers)), std::end(numbers));
}

BOOST_AUTO_TEST_CASE( int_collection_sorted_until_default_compare_not_sorted )
{
    const std::vector<int> numbers{7, 6, 6, 5, 4, 3, 3, 3, 2, 1, 2, 1, 0};
    auto target = std::begin(numbers) + 1;

    BOOST_CHECK_EQUAL(std::is_sorted_until(std::begin(numbers), std::end(numbers)), target);
}

BOOST_AUTO_TEST_CASE( int_collection_sorted_until_custom_compare_sorted )
{
    const std::vector<int> numbers{7, 6, 6, 5, 4, 3, 3, 3, 2, 1, 0};

    BOOST_CHECK_EQUAL(std::is_sorted_until(std::begin(numbers), std::end(numbers), std::greater<int>()), std::end(numbers));
}

BOOST_AUTO_TEST_CASE( int_collection_sorted_until_custom_compare_not_sorted )
{
    const std::vector<int> numbers{7, 6, 6, 5, 4, 3, 3, 3, 2, 1, 2, 1, 0};
    auto target = std::begin(numbers) + 10;

    BOOST_CHECK_EQUAL(std::is_sorted_until(std::begin(numbers), std::end(numbers), std::greater<int>()), target);
}

BOOST_AUTO_TEST_SUITE_END( /* is_sorted_test_suite */ )
