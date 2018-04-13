#ifndef SHAPEGROUP_HPP
#define SHAPEGROUP_HPP

#include "AbstractShape.hpp"

#include <vector>

namespace shape
{
  class ShapeGroup : public AbstractShape
  {
  public:
    ShapeGroup ();

    ShapeGroup (const Point& pos);

    ~ShapeGroup ();

    /*!
     * @brief Add a shape::ShapeInterface to the group
     *
     * @param shape The shape::ShapeInterface to add to the group.
     * @return true if the element is added, otherwise false.
     */
    bool add_shape (ShapeInterface* shape);

    /*!
     * @brief Removes a shape::ShapeInterface from the group
     *
     * @param shape The shape::ShapeInterface to remove from the group
     * @return true if the element is removed, oserwise false.
     */
    bool remove_shape (ShapeInterface* shape);

    //!< Draw all list members.
    void draw ();

    //!< Translate all list member.
    void translate ();

    //!< Rotate all list members.
    void rotate ();

    //!< Overload the == operator
    bool operator== (const ShapeGroup& group);

  private:
    std::vector<ShapeInterface*> m_group;
  };
}
#endif /* !defined(SHAPEGROUP_HPP) */
