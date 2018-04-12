#include "AbstractShape.hpp"

#include <exception>
#include <iostream>
#include <string>

class NotImplementedException : public std::exception
{
  const char* what () const throw () { return "Not implemented function."; }
};

#define DOES_NOTHING(shape) \
  {                         \
    (void) shape;           \
  }

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
    m_x = point.m_x;
    m_y = point.m_y;
    return *this;
  }

  bool Point::operator== (const Point& point) const
  {
    if (point.x () == m_x)
      return (point.y () == m_y);
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
  Point AbstractShape::get_position () const { return m_position; }

  Point AbstractShape::get_rotation_center () const
  {
    return m_rotation_center;
  }

  int AbstractShape::get_color () const { return m_color; }

  // Setters
  void AbstractShape::set_position (const Point& point) { m_position = point; }

  void AbstractShape::set_rotation_center (const Point& point)
  {
    m_rotation_center = point;
  }

  void AbstractShape::set_color (hex color) { m_color = color; }

  // Other methods

  // Preprocessor command to avoid unsued compile error.
  void AbstractShape::add_shape (__attribute__ ((unused))
                                 const ShapeInterface& shape)
  {
    throw NotImplementedException ();
  }

  // Preprocessor command to avoid unsued compile error.
  void AbstractShape::remove_shape (__attribute__ ((unused))
                                    const ShapeInterface& shape)
  {
    throw NotImplementedException ();
  }

  bool AbstractShape::operator== (const AbstractShape& shape)
  {
    if (m_position == shape.get_position ())
      if (m_rotation_center == shape.get_rotation_center ())
        return (m_color == shape.get_color ());
    return false;
  }
}
