#include "TestShape.hpp"

#include <cppunit/ui/text/TextTestRunner.h>

namespace test
{

  void TestShape::setUp ()
  {
    m_point = new shape::Point;
  }

  void TestShape::tearDown ()
  {
    delete m_point;
  }
  
  void TestShape::test_point ()
  {
    CPPUNIT_ASSERT_EQUAL (m_point->x (), 0.0);
    CPPUNIT_ASSERT_EQUAL (m_point->y (), 0.0);
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
