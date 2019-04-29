#ifndef INTERSECT_HPP_INCLUDER
#define INTERSECT_HPP_INCLUDER
#include <iostream>

using namespace std;

inline int area(pair<int, int> a, pair<int, int> b, pair<int, int> c);
inline bool intersect_1(int a, int b, int c, int d);
bool intersect(
        pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d);

#endif