#include "TestRectangle.hpp"

#include <cppunit/ui/text/TextTestRunner.h>

namespace test
{
  CPPUNIT_TEST_SUITE_REGISTRATION (TestRectangle);

  void TestRectangle::test_operators ()
  {
    shape::Rectangle rect (1.0, 1.0, 1.0);
    CPPUNIT_ASSERT (!(m_fixture == rect));

    shape::Rectangle rect_copy = rect;
    CPPUNIT_ASSERT (rect_copy == rect);
    CPPUNIT_ASSERT (!(rect == m_fixture));
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

  void TestRectangle::test_memento ()
  {
    shape::Memento<shape::Rectangle> mem = m_fixture.create_memento ();
    shape::Rectangle m_fixture_copy = m_fixture;
    CPPUNIT_ASSERT (m_fixture == mem.get_state ());
    m_fixture.set_color (69);
    m_fixture.set_height (9);
    m_fixture.set_width (7);
    m_fixture.set_rounding_coeff (3);
    CPPUNIT_ASSERT (!(m_fixture == mem.get_state ()));
    m_fixture.set_memento (mem);
    CPPUNIT_ASSERT (m_fixture == m_fixture_copy);
  }

  void TestRectangle::test_serialize ()
  {
    std::stringstream save_file;
    boost::archive::text_oarchive save_archive (save_file);
    save_archive << m_fixture;

    shape::Rectangle fixture_copy = m_fixture;
    m_fixture.set_width (m_fixture.get_width () - 1);
    m_fixture.set_color (m_fixture.get_color () - 1);
    m_fixture.set_position (shape::Point (42, 69));

    boost::archive::text_iarchive load_archive (save_file);
    load_archive >> m_fixture;
    CPPUNIT_ASSERT (m_fixture == fixture_copy);
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
