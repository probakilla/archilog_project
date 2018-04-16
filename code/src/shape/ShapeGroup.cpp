#include "ShapeGroup.hpp"

#include <algorithm>

namespace shape
{
  ShapeGroup::ShapeGroup () : AbstractShape () {}

  ShapeGroup::ShapeGroup (const Point& pos) : AbstractShape (pos) {}

  bool ShapeGroup::add_shape (ShapeInterface* shape)
  {
    bool found =
     (std::find (m_group.begin (), m_group.end (), shape) != m_group.end ());
    if (!found)
    {
      m_group.push_back (shape);
      return true;
    }
    return false;
  }

  bool ShapeGroup::remove_shape (ShapeInterface* shape)
  {
    std::vector<ShapeInterface*>::iterator it = m_group.begin ();

    it = std::find (m_group.begin (), m_group.end (), shape);
    if (it != m_group.end ())
    {
      m_group.erase (it);
      return true;
    }
    return false;
  }

  std::vector<ShapeInterface*> ShapeGroup::get_group () { return m_group; }

  bool ShapeGroup::operator== (const ShapeInterface& shape)
  {
    if (!(AbstractShape::operator== (shape)))
      return false;
    ShapeGroup group = static_cast<const ShapeGroup&> (shape);
    if (m_group.size () != group.m_group.size ())
      return false;

    for (unsigned int i = 0; i < m_group.size (); ++i)
    {
      if (m_group[i] != group.m_group[i])
        return false;
    }
    return true;
  }

  ShapeGroup& ShapeGroup::operator= (const ShapeGroup& group)
  {
    AbstractShape::operator= (group);
    m_group = group.m_group;
    return *this;
  }

  Memento<ShapeGroup> ShapeGroup::create_memento () const
  {
    return Memento<ShapeGroup> (*this);
  }

  void ShapeGroup::set_memento (Memento<ShapeGroup> m)
  {
    *this = m.get_state ();
  }
}
