#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN all_of any_of none_of tests

#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <vector>

#include "operators.h"
#include "rectangle.h"

using rectangle = rectangle_t<int>;

BOOST_AUTO_TEST_SUITE( all_any_none_of_test_suite )

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
    const rects_variety_fixture f;

    BOOST_CHECK(std::all_of(std::begin(f.rects), std::end(f.rects), true_no_op()));
    BOOST_CHECK(not std::all_of(std::begin(f.rects), std::end(f.rects), false_no_op()));
    BOOST_CHECK(not std::all_of(std::begin(f.rects), std::end(f.rects), alternating_no_op()));
}

BOOST_AUTO_TEST_CASE( no_op_any_of )
{
    const rects_variety_fixture f;

    BOOST_CHECK(std::any_of(std::begin(f.rects), std::end(f.rects), true_no_op()));
    BOOST_CHECK(not std::any_of(std::begin(f.rects), std::end(f.rects), false_no_op()));

    /*! True, as the container has at least 2 elements. */
    BOOST_CHECK(std::any_of(std::begin(f.rects), std::end(f.rects), alternating_no_op()));
}

BOOST_AUTO_TEST_CASE( no_op_none_of )
{
    const rects_variety_fixture f;

    BOOST_CHECK(not std::none_of(std::begin(f.rects), std::end(f.rects), true_no_op()));
    BOOST_CHECK(std::none_of(std::begin(f.rects), std::end(f.rects), false_no_op()));
    BOOST_CHECK(not std::none_of(std::begin(f.rects), std::end(f.rects), alternating_no_op()));
}

BOOST_AUTO_TEST_CASE( is_valid_checks )
{
    const rects_variety_fixture f;

    BOOST_CHECK(not std::all_of(std::begin(f.rects), std::end(f.rects), is_valid<rects_variety_fixture::coord>));
    BOOST_CHECK(std::any_of(std::begin(f.rects), std::end(f.rects), is_valid<rects_variety_fixture::coord>));
    BOOST_CHECK(not std::none_of(std::begin(f.rects), std::end(f.rects), is_valid<rects_variety_fixture::coord>));
}

BOOST_AUTO_TEST_CASE( has_area_valid_rects_fixture )
{
    const valid_rects_fixture f;

    BOOST_REQUIRE(std::all_of(std::begin(f.rects), std::end(f.rects), is_valid<rects_variety_fixture::coord>));

    BOOST_CHECK(not std::all_of(std::begin(f.rects), std::end(f.rects), has_area<rects_variety_fixture::coord>));
    BOOST_CHECK(std::any_of(std::begin(f.rects), std::end(f.rects), has_area<rects_variety_fixture::coord>));
    BOOST_CHECK(not std::none_of(std::begin(f.rects), std::end(f.rects), has_area<rects_variety_fixture::coord>));
}

BOOST_AUTO_TEST_CASE( has_area_positive_area_rects_fixture )
{
    const positive_area_rects_fixture f;

    BOOST_REQUIRE(std::all_of(std::begin(f.rects), std::end(f.rects), is_valid<rects_variety_fixture::coord>));

    BOOST_CHECK(std::all_of(std::begin(f.rects), std::end(f.rects), has_area<rects_variety_fixture::coord>));
    BOOST_CHECK(std::any_of(std::begin(f.rects), std::end(f.rects), has_area<rects_variety_fixture::coord>));
    BOOST_CHECK(not std::none_of(std::begin(f.rects), std::end(f.rects), has_area<rects_variety_fixture::coord>));
}

BOOST_AUTO_TEST_SUITE_END( /* all_of_test_suite */ )
