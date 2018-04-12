#include "TestPoint.hpp"

#include <cppunit/ui/text/TextTestRunner.h>

#define NB_ITER 50

namespace test
{
  CPPUNIT_TEST_SUITE_REGISTRATION (TestPoint);

  void TestPoint::test_constructor ()
  {
    // Empty constructor
    CPPUNIT_ASSERT_EQUAL (m_point.x (), 0.0);
    CPPUNIT_ASSERT_EQUAL (m_point.y (), 0.0);

    // Two double constructor
    shape::Point p (3.0, 4.0);
    CPPUNIT_ASSERT_EQUAL (p.x (), 3.0);
    CPPUNIT_ASSERT_EQUAL (p.y (), 4.0);

    // Copy constructor
    m_point = p;
    CPPUNIT_ASSERT_EQUAL (m_point.x (), 3.0);
    CPPUNIT_ASSERT_EQUAL (m_point.y (), 4.0);
  }

  void TestPoint::test_setter ()
  {
    for (int i = 0; i < NB_ITER; ++i)
    {
      m_point.set_x (i * NB_ITER);
      m_point.set_y (i * i);
      CPPUNIT_ASSERT_EQUAL (m_point.x (), (double) i * (double) NB_ITER);
      CPPUNIT_ASSERT_EQUAL (m_point.y (), (double) i * (double) i);
    }
  }

  void TestPoint::test_equal ()
  {
    for (int i = 0; i < NB_ITER; ++i)
    {
      shape::Point p (i, i * i);
      m_point = p;
      CPPUNIT_ASSERT (m_point == p);
    }
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
