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
    //!< Different color.
    poly_copy.set_color (42);
    CPPUNIT_ASSERT_MESSAGE ("Comparison failed with different color.",
                            !(poly_copy == poly));
    poly_copy = poly;
    CPPUNIT_ASSERT_MESSAGE ("Color wasn't copied.", poly_copy == poly);
    //!< Different position.
    poly_copy.set_position (69);
    CPPUNIT_ASSERT_MESSAGE ("Comparison failed with different position.",
                            !(poly_copy == poly));
    poly_copy = poly;
    CPPUNIT_ASSERT_MESSAGE ("Position wasn't copied", poly_copy == poly);
    //!< Different rotation center
    poly_copy.set_rotation_center (45);
    CPPUNIT_ASSERT_MESSAGE ("Comparison failed with different rotation center.",
                            !(poly_copy == poly));
    poly_copy = poly;
    CPPUNIT_ASSERT_MESSAGE ("Rotation center wasn't copied.",
                            poly_copy == poly);
    //!< Different number of sides.
    poly_copy.set_nb_sides (7);
    CPPUNIT_ASSERT_MESSAGE ("Comparison failed with different sides' number.",
                            !(poly_copy == poly));
    poly_copy = poly;
    CPPUNIT_ASSERT_MESSAGE ("Sides' number wasn't copied.", poly_copy == poly);
    //!< Different side lenght.
    poly_copy.set_side_length (9);
    CPPUNIT_ASSERT_MESSAGE ("Comparison failed with different side lenght.",
                            !(poly_copy == poly));
    poly_copy = poly;
    CPPUNIT_ASSERT_MESSAGE ("Side lenght wasn't copied.", poly_copy == poly);

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
