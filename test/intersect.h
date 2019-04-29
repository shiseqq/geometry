#include "../src/intersect.hpp"
#include <cxxtest/TestSuite.h>
#include <iostream>

class intesection_test : public CxxTest::TestSuite {
public:
    void test_intersection_triangles1()
    {
        TS_ASSERT_EQUALS(intersect({1, 1}, {0, 0}, {-3, -3}, {-2, -2}), 0);
    }
    void test_intersection_triangles2()
    {
        TS_ASSERT_EQUALS(intersect({2, 0}, {1, 1}, {1, 0}, {3, 2}), 1);
    }
};