#ifndef TESTGROUP_HPP
#define TESTGROUP_HPP

#include "ShapeGroup.hpp"

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

namespace test
{
  class TestGroup : public CppUnit::TestCase
  {
    CPPUNIT_TEST_SUITE (TestGroup);
    CPPUNIT_TEST (test_add_remove_shape);
    CPPUNIT_TEST (test_equal);
    CPPUNIT_TEST_SUITE_END ();

  public:
    /*!
     * @brief Test the ShapeGroup::add_shape and ShapeGroup::remove_shape 
     * methods
     *
     * Test to add a shape::Rectangle, a shape::Polygon and an other
     * shape::ShapeGroup and try to remove them after.
     */
    void test_add_remove_shape ();

    /*!
     * @brief Test the operator== overload of the shape::ShapeGroup
     *
     * Test the operator== overload after adding each type of shape including
     * shape::ShapeGroup
     */
    void test_equal ();

  private:
    shape::ShapeGroup fixture;
  };
}
#endif /* !defined(TESTGROUP_HPP) */
