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

    /*!
     * @brief Test the Polygon::create_memento and Polygon::set_memento.
     *
     * Test to create a memento off a shape::Polygon, and restore the
     * shape::Polygon.
     */
    void test_memento ();

  private:
    shape::Polygon m_fixture;
  };
}
#endif /* !defined(TESTPOLYGON_HPP) */
