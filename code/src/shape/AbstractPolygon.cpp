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
}
