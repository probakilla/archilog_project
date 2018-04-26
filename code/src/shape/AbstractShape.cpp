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

  AbstractShape::AbstractShape (const Point& pos, double rotation) :
   m_position (pos), m_rotation_center (pos), m_rotation (rotation)
  {}

  // Getters
  Point AbstractShape::get_position () const { return m_position; }

  Point AbstractShape::get_rotation_center () const
  {
    return m_rotation_center;
  }

  double AbstractShape::get_rotation () const { return m_rotation; }

  // Setters
  void AbstractShape::set_position (const Point& point) { m_position = point; }

  void AbstractShape::set_rotation_center (const Point& point)
  {
    m_rotation_center = point;
  }

  void AbstractShape::set_rotation (double angle) { m_rotation = angle; }

  // Other methods

  void AbstractShape::translate (double dx, double dy)
  {
    m_position.set_x (m_position.x () + dx);
    m_position.set_y (m_position.y () + dy);
    m_rotation_center.set_x (m_rotation_center.x () + dx);
    m_rotation_center.set_y (m_rotation_center.y () + dy);
  }

  bool AbstractShape::add_shape (const ShapeInterface&)
  {
    throw NotImplementedException ();
  }

  bool AbstractShape::remove_shape (const ShapeInterface&)
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

  void AbstractShape::attach (widget::ObserverInterface* obs)
  {
    m_observers.push_back (obs);
  }

  void AbstractShape::detach (widget::ObserverInterface* obs)
  {
    std::vector<widget::ObserverInterface*>::iterator it = m_observers.begin ();

    it = std::find (m_observers.begin (), m_observers.end (), obs);
    if (it != m_observers.end ())
    {
      m_observers.erase (it);
    }
  }

  void AbstractShape::notify ()
  {
    std::vector<widget::ObserverInterface*>::iterator it;
    for (it = m_observers.begin (); it != m_observers.end (); it++)
    {
      (*it)->update_shape ();
    }
  }
}
BOOST_CLASS_EXPORT_IMPLEMENT (shape::AbstractShape);
