#include "AbstractPolygon.hpp"

namespace shape
{
  AbstractPolygon::AbstractPolygon () :
   AbstractShape (), m_color (DEFAULT_COLOR)
  {}

  AbstractPolygon::AbstractPolygon (const Point& pos, hex color) :
   AbstractShape (pos), m_color (color)
  {}

  hex AbstractPolygon::get_color () const { return m_color; }

  void AbstractPolygon::set_color (hex color) { m_color = color; }

  AbstractPolygon& AbstractPolygon::operator= (const AbstractPolygon& poly)
  {
    AbstractShape::operator= (poly);
    m_color = poly.m_color;
    return *this;
  }

  bool AbstractPolygon::operator== (const ShapeInterface& shape)
  {
    if (!AbstractShape::operator== (shape))
      return false;
    return m_color == static_cast<const AbstractPolygon&> (shape).m_color;
  }
}
