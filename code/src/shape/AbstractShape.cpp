#include "AbstractShape.hpp"

namespace shape
{
  // Point structure

  Point::Point (double x, double y) : m_x (x), m_y (y) {}

  Point::Point (const Point& point) : m_x (point.x ()), m_y (point.y ()) {}

  double Point::x () const { return m_x; }

  double Point::y () const { return m_y; }

  void Point::set_x (double x) { m_x = x; }

  void Point::set_y (double y) { m_y = y; }

  Point& Point::operator= (const Point& point)
  {
    m_x = point.x ();
    m_y = point.y ();
    return *this;
  }

  bool Point::operator== (const Point& point) const
  {
    if (point.x () == m_x)
      if (point.y () == m_y)
        return true;
    return false;
  }

  // AbstractShape

  AbstractShape::AbstractShape () : m_color (DEFAULT_COLOR)
  {
    Point default_pos (0, 0);
    m_position = default_pos;
    m_rotation_center = default_pos;
  }

  AbstractShape::AbstractShape (const Point& pos, hex color) :
   m_position (pos), m_rotation_center (pos), m_color (color)
  {}

  // Getters
  Point AbstractShape::position () const { return m_position; }

  Point AbstractShape::rotation_center () const { return m_rotation_center; }

  int AbstractShape::color () const { return m_color; }

  // Setters
  void AbstractShape::set_position (const Point& point) { m_position = point; }

  void AbstractShape::set_rotation_center (const Point& point)
  {
    m_rotation_center = point;
  }

  void AbstractShape::set_color (hex color) { m_color = color; }
}