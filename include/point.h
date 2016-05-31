//
// This header is a helper with a small structure to be used in the unit tests.
//

#ifndef __POINT_H_
#define __POINT_H_

#include <functional>

template <typename coord>
struct point_t
{
    coord x;
    coord y;
};

/*!
 * \brief Equality operator for points.
 */
template <typename coord>
inline bool
operator==(point_t<coord> const& lhs, point_t<coord> const& rhs)
{
    return std::equal_to<coord>()(lhs.x, rhs.x) and std::equal_to<coord>()(lhs.y, rhs.y);
}

/*!
 * \brief Comparison in raster order: Y-coordinate first, then X-coordinate.
 */
template <typename coord>
inline bool
operator<(point_t<coord> const& lhs, point_t<coord> const& rhs)
{
    return std::less<coord>()(lhs.y, rhs.y) or (std::equal_to<coord>()(lhs.y, rhs.y) and std::less<coord>()(lhs.x, rhs.x));
}

#endif /* __POINT_H_ */
