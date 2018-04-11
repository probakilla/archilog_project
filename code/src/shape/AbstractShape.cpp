#include "AbstractShape.hpp"

namespace shape
{
  // Point structure

  Point::Point (double x, double y) : m_x (x), m_y (y) {}

  Point::Point (const Point& point) : m_x (point.get_x ()), m_y (point.get_y ())
  {}

  double Point::get_x () { return m_x; }

  double Point::get_y () { return m_y; }

  void Point::set_x (double x) { m_x = x; }

  void Point::set_y (double y) { m_y = y; }

  Point& Point::operator= (const Point& point)
  {
    m_x = point.get_x ();
    m_y = point.get_y ();
    return *this;
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

  AbstractShape::~AbstractShape ()
  {
    delete m_position;
    delete m_rotation_center;
  }
}
