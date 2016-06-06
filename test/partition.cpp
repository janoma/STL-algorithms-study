#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN partition tests

#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <deque>
#include <iterator>
#include <forward_list>
#include <vector>

BOOST_AUTO_TEST_SUITE( partition_test_suite )

BOOST_AUTO_TEST_CASE( partition_integers_by_less )
{
    std::forward_list<int> numbers{15, -14, -5, -15, 1, 20, -2, 2, -7, -9, -11, 19, -16, 4, 3, -10, -1, 16, 12, 14};

    auto comp = [](int n){ return n < 0; };
    auto it = std::partition(std::begin(numbers), std::end(numbers), comp);

    /*! There are 10 numbers that satisfy the predicate, so that's the expected
     * distance from begin to the returned iterator. */
    BOOST_CHECK_EQUAL(std::distance(std::begin(numbers), it), 10U);
    BOOST_CHECK(std::for_each(std::begin(numbers), it, [](int n){ return n < 0; }));
    BOOST_CHECK(std::for_each(it, std::end(numbers), [](int n){ return n >= 0; }));
}

BOOST_AUTO_TEST_CASE( partition_copy_integers_by_less )
{
    std::forward_list<int> numbers{15, -14, -5, -15, 1, 20, -2, 2, -7, -9, -11, 19, -16, 4, 3, -10, -1, 16, 12, 14};

    std::vector<int> negative;
    std::deque<int> nonnegative;
    auto comp = [](int n){ return n < 0; };
    std::partition_copy(std::begin(numbers), std::end(numbers), std::back_inserter(negative), std::back_inserter(nonnegative), comp);

    BOOST_CHECK_EQUAL(negative.size(), 10);
    BOOST_CHECK_EQUAL(nonnegative.size(), 10);
    BOOST_CHECK(std::for_each(std::begin(negative), std::end(negative), [](int n){ return n < 0; }));
    BOOST_CHECK(std::for_each(std::begin(nonnegative), std::end(nonnegative), [](int n){ return n >= 0; }));
}

BOOST_AUTO_TEST_CASE( stable_partition_integers_by_less )
{
    std::forward_list<int> numbers{15, -14, -5, -15, 1, 20, -2, 2, -7, -9, -11, 19, -16, 4, 3, -10, -1, 16, 12, 14};

    auto comp = [](int n){ return n < 0; };
    auto it = std::stable_partition(std::begin(numbers), std::end(numbers), comp);

    BOOST_CHECK_EQUAL(std::distance(std::begin(numbers), it), 10U);

    const std::forward_list<int> expected{-14, -5, -15, -2, -7, -9, -11, -16, -10, -1, 15, 1, 20, 2, 19, 4, 3, 16, 12, 14};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(numbers), std::end(numbers), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( partition_integers_by_equality )
{
    std::forward_list<int> numbers{1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2};

    auto comp = [](int n){ return n == 2; };
    auto it = std::partition(std::begin(numbers), std::end(numbers), comp);

    BOOST_CHECK_EQUAL(std::distance(std::begin(numbers), it), 6U);

    const std::forward_list<int> expected{2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(numbers), std::end(numbers), std::begin(expected), std::end(expected));
}

BOOST_AUTO_TEST_CASE( partition_copy_integers_by_equality )
{
    std::forward_list<int> numbers{1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1};

    std::vector<int> one;
    std::deque<int> two;
    auto comp = [](int n){ return n == 1; };
    std::partition_copy(std::begin(numbers), std::end(numbers), std::back_inserter(one), std::back_inserter(two), comp);

    BOOST_CHECK_EQUAL(one.size(), 7);
    BOOST_CHECK_EQUAL(two.size(), 6);

    const std::deque<int> expected_one{1, 1, 1, 1, 1, 1, 1};
    const std::vector<int> expected_two{2, 2, 2, 2, 2, 2};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(one), std::end(one), std::begin(expected_one), std::end(expected_one));
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(two), std::end(two), std::begin(expected_two), std::end(expected_two));
}

BOOST_AUTO_TEST_SUITE_END( /* partition_test_suite */ )
