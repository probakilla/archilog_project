#ifndef TESTPOINT_HH
#define TESTPOINT_HH

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#include "AbstractShape.hpp"

namespace test
{
  class TestPoint : public CppUnit::TestFixture
  {
    CPPUNIT_TEST_SUITE (TestPoint);
    CPPUNIT_TEST (test_constructor);
    CPPUNIT_TEST (test_setter);
    CPPUNIT_TEST (test_equal);
    CPPUNIT_TEST_SUITE_END ();

  public:

    /*!
     * @brief Test for the constructors of shape::Point
     *
     * Test the empty constructor, the Point(double, double) constructor and
     * the copy constructor.
     */
    void test_constructor ();

    /*!
     * @brief Test the setters on shape::Point members.
     *
     * Makes a for loop of NB_ITER to test setters.
     */
    void test_setter ();

    //!< Test the Point::operator== overload
    void test_equal ();

  private:
    shape::Point m_point;
  };
}

#endif /* !defined (TESTPOINT_HH)*/
