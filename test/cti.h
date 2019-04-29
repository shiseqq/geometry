#include "../src/cti.hpp"
#include <cxxtest/TestSuite.h>
class MyTest : public CxxTest::TestSuite {
public:
    void test1()
    {
        TS_ASSERT_EQUALS(cti('5'), 5);
    }
    void test2()
    {
        TS_ASSERT_EQUALS(cti('6'), 6);
    }
    void test3()
    {
        TS_ASSERT_EQUALS(cti('7'), 7);
    }
    void test4()
    {
        TS_ASSERT_EQUALS(cti('1'), 1);
    }
    void test5()
    {
        TS_ASSERT_EQUALS(cti('0'), 0);
    }
    void testMethod(void)
    {
        TS_ASSERT_EQUALS(1 + 1, 2);
    }
};
