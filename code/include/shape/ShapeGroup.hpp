#ifndef SHAPEGROUP_HPP
#define SHAPEGROUP_HPP

#include "AbstractShape.hpp"
#include "Memento.hpp"

#include <boost/serialization/vector.hpp>
#include <vector>
namespace shape
{
  class ShapeGroup : public AbstractShape
  {
  public:
    ShapeGroup ();

    ShapeGroup (const Point& pos);

    /*!
     * @brief Add a shape::ShapeInterface to the groupe.
     *
     * @param shape The shape::ShapeInterface to add to the group.
     * @return true if the element is added, otherwise false.
     */
    bool add_shape (ShapeInterface* shape);

    /*!
     * @brief Removes a shape::ShapeInterface from the group.
     *
     * @param shape The shape::ShapeInterface to remove from the group.
     * @return true if the element is removed, oserwise false.
     */
    bool remove_shape (ShapeInterface* shape);

    //!< Getter on ShapeGroup::m_group.
    std::vector<ShapeInterface*> get_group ();

    //!< Comparison operator.
    bool operator== (const ShapeInterface& group) override;

    //!< Copy operator.
    ShapeGroup& operator= (const ShapeGroup& group);

    /*!
     * @brief Create a Memento of shape::ShapeGroup.
     *
     * Create a Memento of shape::ShapeGroup, that store a copy
     * of the object shape::ShapeGroup.
     * @return The memento of shape::ShapeGroup.
     */
    Memento<ShapeGroup> create_memento () const;

    /*!
     * @brief Restaure the state of shape::ShapeGroup.
     *
     * Restaure the state of shape::ShapeGroup with the one in the
     * shape::Memento.
     * @param m The memento used to restaure the state.
     */
    void set_memento (Memento<ShapeGroup> m);

  private:
    std::vector<ShapeInterface*> m_group;

    friend boost::serialization::access;
    template <class Archive> void serialize (Archive& ar, unsigned)
    {
      ar& boost::serialization::base_object<AbstractShape> (*this);
      ar& m_group;
    }
  };
}
BOOST_CLASS_EXPORT_KEY (shape::ShapeGroup);
#endif /* !defined(SHAPEGROUP_HPP) */
