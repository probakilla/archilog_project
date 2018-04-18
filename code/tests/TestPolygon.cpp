#include "TestPolygon.hpp"

#include "Memento.hpp"

#include <cppunit/ui/text/TextTestRunner.h>

namespace test
{
  CPPUNIT_TEST_SUITE_REGISTRATION (TestPolygon);

  void TestPolygon::test_operators ()
  {
    shape::Polygon poly (1, 1.0);
    CPPUNIT_ASSERT (!(m_fixture == poly));

    shape::Polygon poly_copy = poly;
    CPPUNIT_ASSERT (poly_copy == poly);
    CPPUNIT_ASSERT (!(poly == m_fixture));
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

  void TestPolygon::test_memento ()
  {
    shape::Memento<shape::Polygon> mem = m_fixture.create_memento ();
    shape::Polygon m_fixture_copy = m_fixture;
    CPPUNIT_ASSERT (m_fixture == mem.get_state ());
    m_fixture.set_color (69);
    m_fixture.set_side_length (7);
    m_fixture.set_nb_sides (3);
    CPPUNIT_ASSERT (!(m_fixture == mem.get_state ()));
    m_fixture.set_memento (mem);
    CPPUNIT_ASSERT (m_fixture == m_fixture_copy);
  }

  void TestPolygon::test_serialize ()
  {
    std::stringstream save_file;
    boost::archive::text_oarchive save_archive (save_file);
    save_archive << m_fixture;

    shape::Polygon fixture_copy = m_fixture;
    m_fixture.set_side_length (m_fixture.get_side_length () - 1);

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
