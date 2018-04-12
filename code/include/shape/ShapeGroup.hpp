#ifndef SHAPEGROUP_HPP
#define SHAPEGROUP_HPP

#include "AbstractShape.hpp"

#include <list>

namespace shape
{
  class ShapeGroup : public AbstractShape
  {
  public:
    ShapeGroup ();
    ~ShapeGroup ();

    /*!
     * @brief Add a shape::ShapeInterface to the group
     *
     * @param shape The shape::ShapeInterface to add to the group.
     */
    //void add_shape (const ShapeInterface& shape);

    /*!
     * @brief Removes a shape::ShapeInterface from the group
     *
     * @param shape The shape::ShapeInterface to remove from the group
     */
    //void remove_shape (const ShapeInterface& shape);

  private:
    //std::list<ShapeInterface> m_group;
  };
}
#endif /* !defined(SHAPEGROUP_HPP) */
