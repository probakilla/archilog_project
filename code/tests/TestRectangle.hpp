#ifndef TESTRECTANGLE_HPP
#define TESTRECTANGLE_HPP

#include "Rectangle.hpp"

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

namespace test
{
  class TestRectangle : public CppUnit::TestCase
  {
    CPPUNIT_TEST_SUITE (TestRectangle);
    CPPUNIT_TEST (test_operators);
    CPPUNIT_TEST (test_memento);
    CPPUNIT_TEST (test_serialize);
    CPPUNIT_TEST_SUITE_END ();

  public:
    /*!
     * @brief Test the operators overloading of shape::Rectangle
     *
     * Test the operator== and operator= of the shape::Rectangle
     */
    void test_operators ();

    /*!
     * @brief Test the Rectangle::create_memento and Rectangle::set_memento.
     *
     * Test to create a memento off a shape::Rectangle, and restore the
     * shape::Rectangle.
     */
    void test_memento ();

    /*!
     * @brief Test the Rectangle::serialize.
     *
     * Test to save a shape::Rectangle and load it.
     */
    void test_serialize ();

  private:
    shape::Rectangle m_fixture;
  };
}
#endif /* !defined(TESTRECTANGLE_HPP) */
