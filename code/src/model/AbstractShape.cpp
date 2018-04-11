#include "AbstractShape.hpp"

namespace model
{
  // Point structure

  Point::Point (int x, int y) : m_x (x), m_y (y) {}

  int Point::get_x () { return m_x; }

  int Point::get_y () { return m_y; }

  void Point::set_x (const int& x) { m_x = x; }

  void Point::set_y (const int& y) { m_y = y; }

  Point& Point::operator= (const Point& point)
  {
    m_x = point.get_x ();
    m_y = point.get_y ();
  }

  bool Point::operator== (const Point& point)
  {
    if (point.get_x == m_x)
      if (point.get_y == m_y)
        return true;
    return false;
  }

  // AbstractShape
  
  AbstractShape::AbstractShape (Point pos) :
   m_position (pos), m_rotation_center (pos)
  {}
}
