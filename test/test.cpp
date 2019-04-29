/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTest_init = false;
#include "/home/shise/myProj/geometry/test/cti.h"

static MyTest suite_MyTest;

static CxxTest::List Tests_MyTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTest( "test/cti.h", 3, "MyTest", suite_MyTest, Tests_MyTest );

static class TestDescription_suite_MyTest_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_test1() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 5, "test1" ) {}
 void runTest() { suite_MyTest.test1(); }
} testDescription_suite_MyTest_test1;

static class TestDescription_suite_MyTest_test2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_test2() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 9, "test2" ) {}
 void runTest() { suite_MyTest.test2(); }
} testDescription_suite_MyTest_test2;

static class TestDescription_suite_MyTest_test3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_test3() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 13, "test3" ) {}
 void runTest() { suite_MyTest.test3(); }
} testDescription_suite_MyTest_test3;

static class TestDescription_suite_MyTest_test4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_test4() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 17, "test4" ) {}
 void runTest() { suite_MyTest.test4(); }
} testDescription_suite_MyTest_test4;

static class TestDescription_suite_MyTest_test5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_test5() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 21, "test5" ) {}
 void runTest() { suite_MyTest.test5(); }
} testDescription_suite_MyTest_test5;

static class TestDescription_suite_MyTest_testMethod : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_testMethod() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 25, "testMethod" ) {}
 void runTest() { suite_MyTest.testMethod(); }
} testDescription_suite_MyTest_testMethod;

#include "/home/shise/myProj/geometry/test/intersect.h"

static intesection_test suite_intesection_test;

static CxxTest::List Tests_intesection_test = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_intesection_test( "test/intersect.h", 5, "intesection_test", suite_intesection_test, Tests_intesection_test );

static class TestDescription_suite_intesection_test_test_intersection_triangles1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_intesection_test_test_intersection_triangles1() : CxxTest::RealTestDescription( Tests_intesection_test, suiteDescription_intesection_test, 7, "test_intersection_triangles1" ) {}
 void runTest() { suite_intesection_test.test_intersection_triangles1(); }
} testDescription_suite_intesection_test_test_intersection_triangles1;

static class TestDescription_suite_intesection_test_test_intersection_triangles2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_intesection_test_test_intersection_triangles2() : CxxTest::RealTestDescription( Tests_intesection_test, suiteDescription_intesection_test, 11, "test_intersection_triangles2" ) {}
 void runTest() { suite_intesection_test.test_intersection_triangles2(); }
} testDescription_suite_intesection_test_test_intersection_triangles2;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
