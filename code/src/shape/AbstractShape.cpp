#include "AbstractShape.hpp"

#include <exception>
#include <iostream>
#include <string>
#include <typeinfo>

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

  AbstractShape::AbstractShape ()
  {
    Point default_pos (0, 0);
    m_position = default_pos;
    m_rotation_center = default_pos;
  }

  AbstractShape::AbstractShape (const Point& pos) :
   m_position (pos), m_rotation_center (pos)
  {}

  // Getters
  Point AbstractShape::get_position () const { return m_position; }

  Point AbstractShape::get_rotation_center () const
  {
    return m_rotation_center;
  }

  // Setters
  void AbstractShape::set_position (const Point& point) { m_position = point; }

  void AbstractShape::set_rotation_center (const Point& point)
  {
    m_rotation_center = point;
  }

  // Other methods

  // Preprocessor command to avoid unsued compile error.
  bool AbstractShape::add_shape (__attribute__ ((unused))
                                 const ShapeInterface& shape)
  {
    throw NotImplementedException ();
  }

  // Preprocessor command to avoid unsued compile error.
  bool AbstractShape::remove_shape (__attribute__ ((unused))
                                    const ShapeInterface& shape)
  {
    throw NotImplementedException ();
  }

  bool AbstractShape::operator== (const ShapeInterface& shape)
  {
    if (typeid (*this) != typeid (shape))
      return false;
    return m_position ==
            static_cast<const AbstractShape&> (shape).get_position () &&
           m_rotation_center ==
            static_cast<const AbstractShape&> (shape).get_rotation_center ();
  }

  AbstractShape& AbstractShape::operator= (const AbstractShape& shape)
  {
    m_position = shape.get_position ();
    m_rotation_center = shape.get_rotation_center ();
    return *this;
  }
}
BOOST_CLASS_EXPORT_IMPLEMENT(shape::AbstractShape);
