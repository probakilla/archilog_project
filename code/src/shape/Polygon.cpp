#include "Polygon.hpp"

namespace shape
{
  Polygon::Polygon (int nb_sides, double side_length) :
   AbstractPolygon (), m_nb_sides (nb_sides), m_side_length (side_length)
  {}

  Polygon::Polygon (const Point& pos, int nb_sides, double side_length) :
   AbstractPolygon (pos), m_nb_sides (nb_sides), m_side_length (side_length)
  {}

  Polygon& Polygon::operator= (const Polygon& poly)
  {
    AbstractPolygon::operator= (poly);
    m_nb_sides = poly.m_nb_sides;
    m_side_length = poly.m_side_length;
    return *this;
  }

  bool Polygon::operator== (const ShapeInterface& shape)
  {
    if (!AbstractPolygon::operator== (shape))
      return false;
    if (m_nb_sides == static_cast<const Polygon&> (shape).m_nb_sides)
      if (m_side_length == static_cast<const Polygon&> (shape).m_side_length)
        return true;
    return false;
  }

  int Polygon::get_nb_sides () const { return m_nb_sides; }

  double Polygon::get_side_length () const { return m_side_length; }

  void Polygon::set_nb_sides (int nb_sides) { m_nb_sides = nb_sides; }

  void Polygon::set_side_length (double side_length)
  {
    m_side_length = side_length;
  }

  Memento<Polygon> Polygon::create_memento () const
  {
    return Memento<Polygon> (*this);
  }

  void Polygon::set_memento (Memento<Polygon> m) { *this = m.get_state (); }
}

BOOST_CLASS_EXPORT_IMPLEMENT (shape::Polygon);
