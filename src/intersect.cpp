#include "intersect.hpp"

inline int area(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return (b.first - a.first) * (c.second - a.second)
            - (b.second - a.second) * (c.first - a.first);
}

inline bool intersect_1(int a, int b, int c, int d)
{
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool intersect(
        pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d)
{
    return intersect_1(a.first, b.first, c.first, d.first)
            && intersect_1(a.second, b.second, c.second, d.second)
            && area(a, b, c) * area(a, b, d) <= 0
            && area(c, d, a) * area(c, d, b) <= 0;
}