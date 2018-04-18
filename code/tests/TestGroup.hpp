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
    CPPUNIT_TEST (test_memento);
    CPPUNIT_TEST (test_serialize);
    CPPUNIT_TEST_SUITE_END ();

  public:
    /*!
     * @brief Test the ShapeGroup::add_shape and ShapeGroup::remove_shape
     * methods.
     *
     * Test to add a shape::Rectangle, a shape::Polygon and an other
     * shape::ShapeGroup and try to remove them after.
     */
    void test_add_remove_shape ();

    /*!
     * @brief Test the operator== overload of the shape::ShapeGroup.
     *
     * Test the operator== overload after adding each type of shape including
     * shape::ShapeGroup.
     */
    void test_equal ();

    /*!
     * @brief Test the ShapeGroup::create_memento and ShapeGroup::set_memento.
     *
     * Test to create a memento off a shape::ShapeGroup, and restore the
     * shape::ShapeGroup.
     */
    void test_memento ();

    /*!
     * @brief Test the ShapeGroup::serialize.
     *
     * Test to save a shape::ShapeGroup and load it.
     */
    void test_serialize ();

  private:
    shape::ShapeGroup m_fixture;
  };
}
#endif /* !defined(TESTGROUP_HPP) */
