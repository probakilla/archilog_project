#include "TestGroup.hpp"

#include "Polygon.hpp"
#include "Rectangle.hpp"
#include "ShapeInterface.hpp"

#include <cppunit/ui/text/TextTestRunner.h>
#include <vector>

namespace test
{
  CPPUNIT_TEST_SUITE_REGISTRATION (TestGroup);

  void TestGroup::test_add_remove_shape ()
  {
    shape::Rectangle rect;
    CPPUNIT_ASSERT (m_fixture.add_shape (&rect));

    shape::Polygon poly;
    CPPUNIT_ASSERT (m_fixture.add_shape (&poly));

    shape::ShapeGroup sub_group;
    CPPUNIT_ASSERT (sub_group.add_shape (&rect));
    CPPUNIT_ASSERT (sub_group.add_shape (&poly));
    CPPUNIT_ASSERT (m_fixture.add_shape (&sub_group));

    std::vector<shape::ShapeInterface*> vector_test = m_fixture.get_group ();
    CPPUNIT_ASSERT (vector_test[0] == &rect);
    CPPUNIT_ASSERT (vector_test[1] == &poly);
    CPPUNIT_ASSERT (vector_test[2] == &sub_group);

    CPPUNIT_ASSERT (m_fixture.remove_shape (&rect));
    CPPUNIT_ASSERT (m_fixture.remove_shape (&poly));
    CPPUNIT_ASSERT (m_fixture.remove_shape (&sub_group));
  }

  void TestGroup::test_equal ()
  {
    shape::ShapeGroup group;
    CPPUNIT_ASSERT (group == m_fixture);

    shape::Rectangle rect;
    group.add_shape (&rect);
    CPPUNIT_ASSERT (!(group == m_fixture));

    m_fixture.add_shape (&rect);
    CPPUNIT_ASSERT (group == m_fixture);

    shape::Polygon poly;
    group.add_shape (&poly);
    CPPUNIT_ASSERT (!(poly == m_fixture));

    m_fixture.add_shape (&poly);
    CPPUNIT_ASSERT (group == m_fixture);

    shape::ShapeGroup sub_group;
    sub_group.add_shape (&rect);
    sub_group.add_shape (&poly);
    CPPUNIT_ASSERT (sub_group == group);

    m_fixture.add_shape (&sub_group);
    CPPUNIT_ASSERT (!(group == m_fixture));

    group.add_shape (&sub_group);
    CPPUNIT_ASSERT (group == m_fixture);
  }

  void TestGroup::test_memento ()
  {
    shape::Memento<shape::ShapeGroup> mem = m_fixture.create_memento ();
    shape::ShapeGroup m_fixture_copy = m_fixture;
    CPPUNIT_ASSERT (m_fixture == mem.get_state ());
    m_fixture.add_shape (new shape::Rectangle ());
    CPPUNIT_ASSERT (!(m_fixture == mem.get_state ()));
    m_fixture.set_memento (mem);
    CPPUNIT_ASSERT (m_fixture == m_fixture_copy);
  }

  void TestGroup::test_serialize ()
  {
    shape::Rectangle rect;
    m_fixture.add_shape (&rect);
    shape::Polygon poly;
    m_fixture.add_shape (&poly);

    std::stringstream save_file;
    boost::archive::text_oarchive save_archive (save_file);
    save_archive << m_fixture;

    shape::ShapeGroup fixture_copy = m_fixture;
    m_fixture.remove_shape (&rect);

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
