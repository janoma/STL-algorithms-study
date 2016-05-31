//
// This header is a helper with a small structure to be used in the unit tests.
// Collections and queries will be based on this.
//

#ifndef __POINT_H_
#define __POINT_H_

template <typename coord = int>
struct point
{
    coord x;
    coord y;
};

#endif /* __POINT_H_ */
