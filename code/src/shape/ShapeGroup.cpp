#include "ShapeGroup.hpp"

#include <algorithm>

namespace shape
{
  ShapeGroup::ShapeGroup () {}
  ShapeGroup::~ShapeGroup () {}

  void ShapeGroup::add_shape (ShapeInterface* shape)
  {
    bool found =
     (std::find (m_group.begin (), m_group.end (), shape) != m_group.end ());
    if (!found)
      m_group.push_back (shape);
  }

  void ShapeGroup::remove_shape (ShapeInterface* shape)
  {
    std::vector<ShapeInterface*>::iterator it = m_group.begin ();

    it = std::find (m_group.begin (), m_group.end (), shape);
    if (it != m_group.end ())
      m_group.erase (it);
  }

  void ShapeGroup::draw ()
  {
    for (const auto& it : m_group)
      it->draw ();
  }

  void ShapeGroup::translate ()
  {
    for (const auto& it : m_group)
      it->translate ();
  }

  void ShapeGroup::rotate ()
  {
    for (auto const& it : m_group)
      it->rotate ();
  }

  bool ShapeGroup::operator== (const ShapeGroup& group)
  {
    if (m_group.size () != group.m_group.size ())
      return false;

    for (unsigned int i = 0; i < m_group.size (); ++i)
    {
      if (m_group [i] != group.m_group [i])
	return false;
    }
    return true;
  }
}
