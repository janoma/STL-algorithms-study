//
// This header is a helper with a small structure to be used in the unit tests.
//

#ifndef __POINT_H_
#define __POINT_H_

#include <algorithm>
#include <functional>
#include <ostream>
#include <vector>

#include "rectangle.h"

template <typename coord>
struct point_t
{
    coord x;
    coord y;

    /*!
     * \brief Implicit conversion from point to rectangle.
     *
     * \details The geometric interpretation of this conversion might not be
     * really useful, but it is an interesting addition for some of the
     * examples.
     */
    inline operator rectangle_t<coord>() const
    {
        return rectangle_t<coord>{
            std::min(0, x), std::min(0, y),
            std::max(0, x), std::max(0, y)
        };
    }
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

/*!
 * \brief Alternative comparison to be passed to specific algorithms: raster by
 * X first (increasing), then Y (decreasing).
 */
struct raster_by_x
{
    template <typename coord>
    inline bool
    operator()(point_t<coord> const& lhs, point_t<coord> const& rhs) const
    {
        return std::less<coord>()(lhs.x, rhs.x) or (std::equal_to<coord>()(lhs.x, rhs.x) and std::greater<coord>()(lhs.y, rhs.y));
    }
};

/*!
 * \brief Operator to print a point to console. Used by Boost.Test.
 */
template <typename coord>
inline std::ostream&
operator<<(std::ostream& out, point_t<coord> const& p)
{
    return out << "(" << p.x << "," << p.y << ")";
}

/*!
 * \brief Fixture for Boost.Test with repeated points, etc.
 */
struct points_variety_fixture
{
    using coord = int;
    using point = point_t<coord>;

    points_variety_fixture()
    {
        points.push_back(point{0, 0});
        points.push_back(point{5, 0});
        points.push_back(point{0, 5});
        points.push_back(point{10, 20});
        points.push_back(point{0, 0});
        points.push_back(point{5, 0});
        points.push_back(point{100, 100});
        points.push_back(point{20, 0});
        points.push_back(point{40, 10});
        points.push_back(point{0, 0});
    }

    std::vector<point> points;
};

#endif /* __POINT_H_ */
