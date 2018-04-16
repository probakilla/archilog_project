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
    //!< Different color.
    rect_copy.set_color (42);
    CPPUNIT_ASSERT_MESSAGE ("Comparison failed with different color.",
                            !(rect_copy == rect));
    rect_copy = rect;
    CPPUNIT_ASSERT_MESSAGE ("Color wasn't copied.", rect_copy == rect);
    //!< Different position.
    rect_copy.set_position (69);
    CPPUNIT_ASSERT_MESSAGE ("Comparison failed with different position.",
                            !(rect_copy == rect));
    rect_copy = rect;
    CPPUNIT_ASSERT_MESSAGE ("Position wasn't copied", rect_copy == rect);
    //!< Different rotation center
    rect_copy.set_rotation_center (45);
    CPPUNIT_ASSERT_MESSAGE ("Comparison failed with different rotation center.",
                            !(rect_copy == rect));
    rect_copy = rect;
    CPPUNIT_ASSERT_MESSAGE ("Rotation center wasn't copied.",
                            rect_copy == rect);
    //!< Different height.
    rect_copy.set_height (7);
    CPPUNIT_ASSERT_MESSAGE ("Comparison failed with different height.",
                            !(rect_copy == rect));
    rect_copy = rect;
    CPPUNIT_ASSERT_MESSAGE ("Height wasn't copied.", rect_copy == rect);
    //!< Different width.
    rect_copy.set_width (9);
    CPPUNIT_ASSERT_MESSAGE ("Comparison failed with different width.",
                            !(rect_copy == rect));
    rect_copy = rect;
    CPPUNIT_ASSERT_MESSAGE ("Width wasn't copied.", rect_copy == rect);
    //!< Different rounding coeff.
    rect_copy.set_rounding_coeff (10);
    CPPUNIT_ASSERT_MESSAGE ("Comparison failed with different rounding coeff.",
                            !(rect_copy == rect));
    rect_copy = rect;
    CPPUNIT_ASSERT_MESSAGE ("Rounding coeff wasn't copied.", rect_copy == rect);

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
