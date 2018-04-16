#ifndef TESTPOLYGON_HPP
#define TESTPOLYGON_HPP

#include "Polygon.hpp"

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

namespace test
{
  class TestPolygon : public CppUnit::TestCase
  {
    CPPUNIT_TEST_SUITE (TestPolygon);
    CPPUNIT_TEST (test_operators);
    CPPUNIT_TEST_SUITE_END ();

  public:
    /*!
     * @brief Test the operators overloading of shape::Polygon
     *
     * Test the operator== and operator= of the shape::Polygon
     */
    void test_operators ();

  private:
    shape::Polygon fixture;
  };
}
#endif /* !defined(TESTPOLYGON_HPP) */
