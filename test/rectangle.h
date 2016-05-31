//
// This header is a helper with a small structure to be used in the unit tests.
// Collections and queries will be based on this.
//

#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include <cassert>
#include <functional>

template <typename coord>
struct rectangle_t
{
    coord left;
    coord bottom;
    coord right;
    coord top;
};

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
    return std::less_equal<coord>(rect.left, rect.right) and std::less_equal<coord>(rect.right, rect.top);
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
    return std::multiplies<coord>(std::minus<coord>(rect.right, rect.left), std::minus<coord>(rect.top, rect.bottom));
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
    return std::less<coord>(rect.left, rect.right) and std::less<coord>(rect.right, rect.top);
}

#endif /* __RECTANGLE_H_ */
