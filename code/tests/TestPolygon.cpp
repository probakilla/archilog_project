#include "TestPolygon.hpp"

#include <cppunit/ui/text/TextTestRunner.h>

namespace test
{
  CPPUNIT_TEST_SUITE_REGISTRATION (TestPolygon);

  void TestPolygon::test_operators ()
  {
    shape::Polygon poly (1, 1.0);
    CPPUNIT_ASSERT (!(fixture == poly));

    shape::Polygon poly_copy = poly;
    CPPUNIT_ASSERT (poly_copy == poly);
    CPPUNIT_ASSERT (!(poly == fixture));

    shape::Point pts (1, 2);
    shape::Polygon poly_pts (pts, 2, 2.0);
    CPPUNIT_ASSERT (!(poly == poly_pts));

    shape::Polygon poly_pts_copy = poly_pts;
    CPPUNIT_ASSERT (poly_pts_copy == poly_pts);
  }
}

int main ()
{
  CppUnit::Test* test =
   CppUnit::TestFactoryRegistry::getRegistry ().makeTest ();
  CppUnit::TextTestRunner runner;
  runner.addTest (test);
  bool failed = runner.run ("", false);
  return !failed;
}
