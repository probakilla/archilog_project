#ifndef TESTSHAPE_HH
#define TESTSHAPE_HH

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "AbstractShape.hpp"

namespace test
{
  class TestShape : public CppUnit::TestFixture
  {
    CPPUNIT_TEST_SUITE (TestShape);
    CPPUNIT_TEST (test_point);
    CPPUNIT_TEST_SUITE_END ();

  public:
    void setUp ();

    void tearDown ();

    void test_point ();

  private:
    shape::Point* m_point;
  };
}

#endif /* !defined (TEST_SHAPE_HH)*/
