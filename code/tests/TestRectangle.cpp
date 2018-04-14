#include "TestRectangle.hpp"

#include <cppunit/ui/text/TextTestRunner.h>

namespace test
{
  CPPUNIT_TEST_SUITE_REGISTRATION (TestRectangle);

  void TestRectangle::test_operators ()
  {
    shape::Rectangle rect (1.0, 1.0, 1.0);
    CPPUNIT_ASSERT (!(fixture == rect));

    shape::Rectangle rect_copy = rect;
    CPPUNIT_ASSERT (rect_copy == rect);
    CPPUNIT_ASSERT (!(rect == fixture));

    shape::Point pts (1, 2);
    shape::Rectangle rect_pts (pts, 2.0, 2.0, 3.0);
    CPPUNIT_ASSERT (!(rect == rect_pts));

    shape::Rectangle rect_pts_copy = rect_pts;
    CPPUNIT_ASSERT (rect_pts_copy == rect_pts);
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
