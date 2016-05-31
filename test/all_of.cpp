#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN all_of any_of none_of tests

#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <vector>

#include "operators.h"
#include "rectangle.h"

using rectangle = rectangle_t<int>;

struct rects_fixture
{
    rects_fixture()
    {
        rects.push_back(rectangle{0, 0, 20, 5}); /*! valid, area 100 */
        rects.push_back(rectangle{10, 0, 50, 10}); /* valid, area 400 */
        rects.push_back(rectangle{20, 30, 50, 40}); /* valid, area 300 */
        rects.push_back(rectangle{50, 0, 20, 20}); /*! invalid */
        rects.push_back(rectangle{50, 0, 50, 20}); /*! valid, area 0 */
        rects.push_back(rectangle{50, 0, 70, 0}); /*! valid, area 0 */
        rects.push_back(rectangle{0, 0, -1, -1}); /*! invalid */
        rects.push_back(rectangle{0, 0, 1, 1}); /*! valid, area 1 */
        rects.push_back(rectangle{0, 0, 2, 10}); /*! valid, area 20 */
    }

    std::vector<rectangle> rects;
};

BOOST_AUTO_TEST_SUITE( all_of_test_suite )

BOOST_AUTO_TEST_CASE( empty_container_all_of )
{
    std::vector<rectangle> rects;

    /*! True regardless of the predicate, as all elements in the container
     * satisfy the predicate trivially. */
    BOOST_CHECK(std::all_of(std::begin(rects), std::end(rects), true_no_op()));
    BOOST_CHECK(std::all_of(std::begin(rects), std::end(rects), false_no_op()));
}

BOOST_AUTO_TEST_CASE( empty_container_any_of )
{
    std::vector<rectangle> rects;

    /*! True regardless of the predicate, as none of the elements in the
     * container make the predicate return false. */
    BOOST_CHECK(std::none_of(std::begin(rects), std::end(rects), true_no_op()));
    BOOST_CHECK(std::none_of(std::begin(rects), std::end(rects), false_no_op()));
}

BOOST_AUTO_TEST_CASE( empty_container_none_of )
{
    std::vector<rectangle> rects;

    /*! Note the definition for any_of: "returns true if the predicate returns
     * true for *at least one* element in the range. Since the range has no
     * elements, if must return false for any predicate, as there is no
     * 'witness'. */
    BOOST_CHECK(not std::any_of(std::begin(rects), std::end(rects), true_no_op()));
    BOOST_CHECK(not std::any_of(std::begin(rects), std::end(rects), false_no_op()));
}

BOOST_AUTO_TEST_CASE( no_op_all_of )
{
    const rects_fixture f;

    BOOST_CHECK(std::all_of(std::begin(f.rects), std::end(f.rects), true_no_op()));
    BOOST_CHECK(not std::all_of(std::begin(f.rects), std::end(f.rects), false_no_op()));
    BOOST_CHECK(not std::all_of(std::begin(f.rects), std::end(f.rects), alternating_no_op()));
}

BOOST_AUTO_TEST_CASE( no_op_any_of )
{
    const rects_fixture f;

    BOOST_CHECK(std::any_of(std::begin(f.rects), std::end(f.rects), true_no_op()));
    BOOST_CHECK(not std::any_of(std::begin(f.rects), std::end(f.rects), false_no_op()));

    /*! True, as the container has at least 2 elements. */
    BOOST_CHECK(std::any_of(std::begin(f.rects), std::end(f.rects), alternating_no_op()));
}

BOOST_AUTO_TEST_CASE( no_op_none_of )
{
    const rects_fixture f;

    BOOST_CHECK(not std::none_of(std::begin(f.rects), std::end(f.rects), true_no_op()));
    BOOST_CHECK(std::none_of(std::begin(f.rects), std::end(f.rects), false_no_op()));
    BOOST_CHECK(not std::none_of(std::begin(f.rects), std::end(f.rects), alternating_no_op()));
}

BOOST_AUTO_TEST_SUITE_END( /* STL_Algorithm_all_of_Test_Suite */ )
