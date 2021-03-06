//
// This header is a helper with a small structure to be used in the unit tests.
//

#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include <cassert>
#include <functional>
#include <vector>

template <typename coord>
struct rectangle_t
{
    coord left;
    coord bottom;
    coord right;
    coord top;
};

template <typename coord>
inline bool
operator==(rectangle_t<coord> const& lhs, rectangle_t<coord> const& rhs)
{
    return lhs.left == rhs.left and
        lhs.bottom == rhs.bottom and
        lhs.right == rhs.right and
        lhs.top == rhs.top;
}

/*!
 * \brief Returns true if the rectangle is valid.
 *
 * \details A rectangle is valid if the left coordinate is less or equal than
 * the right coordinate and the bottom coordinate is less or equal than the top
 * coordinate. This does not rule out zero-width or zero-height rectangles.
 */
template <typename coord>
inline bool
is_valid(rectangle_t<coord> const& rect)
{
    return std::less_equal<coord>()(rect.left, rect.right) and std::less_equal<coord>()(rect.bottom, rect.top);
}

/*!
 * \brief Computes the area of a valid rectangle.
 *
 * \pre The rectangle is valid.
 *
 * \note It is a limitation to store the area of a rectangle in its own
 * coordinate type, as this may produce overflow for large enough rectangles of
 * integral coordinates. However, as this is only used for a small sample, it
 * will be ignored.
 */
template <typename coord>
inline coord
area(rectangle_t<coord> const& rect)
{
    assert(is_valid(rect));
    return std::multiplies<coord>()(std::minus<coord>()(rect.right, rect.left), std::minus<coord>()(rect.top, rect.bottom));
}

/*!
 * \brief Returns true if the rectangle has positive area.
 *
 * \sa area
 */
template <typename coord>
inline bool
has_area(rectangle_t<coord> const& rect)
{
    /*! Alternative implementation: return area(rect) > 0 */
    return std::less<coord>()(rect.left, rect.right) and std::less<coord>()(rect.bottom, rect.top);
}

/*!
 * \brief Returns true if the rectangles have the same area.
 *
 * \sa area
 */
template <typename coord>
inline bool
same_area(rectangle_t<coord> const& lhs, rectangle_t<coord> const& rhs)
{
    return std::equal_to<coord>()(area(lhs), area(rhs));
}

template <typename coord>
struct compare_by_area
{
    inline bool
    operator()(rectangle_t<coord> const& lhs, rectangle_t<coord> const& rhs) const
    {
        return std::less<coord>()(area(lhs), area(rhs));
    }
};

/*!
 * Fixture for Boost.Test with a variety of rectangles, including invalid
 * rectangles.
 */
struct rects_variety_fixture
{
    using coord = int;
    using rectangle = rectangle_t<coord>;

    rects_variety_fixture()
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

/*!
 * Fixture for Boost.Test containing only valid rectangles, some of them with
 * zero area.
 */
struct valid_rects_fixture
{
    using coord = int;
    using rectangle = rectangle_t<coord>;

    valid_rects_fixture()
    {
        rects.push_back(rectangle{0, 0, 20, 5}); /*! valid, area 100 */
        rects.push_back(rectangle{10, 0, 50, 10}); /* valid, area 400 */
        rects.push_back(rectangle{20, 30, 50, 40}); /* valid, area 300 */
        rects.push_back(rectangle{50, 0, 70, 20}); /*! valid, area 400 */
        rects.push_back(rectangle{50, 0, 50, 20}); /*! valid, area 0 */
        rects.push_back(rectangle{50, 0, 70, 0}); /*! valid, area 0 */
        rects.push_back(rectangle{0, 0, 1, 1}); /*! valid, area 1 */
        rects.push_back(rectangle{0, 0, 1, 1}); /*! valid, area 1 */
        rects.push_back(rectangle{0, 0, 2, 10}); /*! valid, area 20 */
    }

    std::vector<rectangle> rects;
};

/*!
 * Fixture for Boost.Test containing only valid rectangles with positive area.
 */
struct positive_area_rects_fixture
{
    using coord = int;
    using rectangle = rectangle_t<coord>;

    positive_area_rects_fixture()
    {
        rects.push_back(rectangle{0, 0, 20, 5}); /*! valid, area 100 */
        rects.push_back(rectangle{10, 0, 50, 10}); /* valid, area 400 */
        rects.push_back(rectangle{0, 0, 1, 1}); /*! valid, area 1 */
        rects.push_back(rectangle{20, 30, 50, 40}); /* valid, area 300 */
        rects.push_back(rectangle{50, 0, 70, 20}); /*! valid, area 400 */
        rects.push_back(rectangle{50, 0, 55, 20}); /*! valid, area 100 */
        rects.push_back(rectangle{50, 0, 70, 5}); /*! valid, area 100 */
        rects.push_back(rectangle{0, 0, 1, 1}); /*! valid, area 1 */
        rects.push_back(rectangle{0, 0, 1, 1}); /*! valid, area 1 */
        rects.push_back(rectangle{0, 0, 2, 10}); /*! valid, area 20 */
        rects.push_back(rectangle{0, 0, 1, 1}); /*! valid, area 1 */
    }

    std::vector<rectangle> rects;
};

#endif /* __RECTANGLE_H_ */
