#include "QtPolygon.hpp"

#include <iostream>

namespace shape
{
  QtPolygon::QtPolygon (int nb_sides, double side_length) :
   Polygon (nb_sides, side_length)
  {}

  QtPolygon::QtPolygon (const Point& pos, int nb_sides, double side_length) :
   Polygon (pos, nb_sides, side_length)
  {}

  void QtPolygon::draw ()
  {
    // Temporary
    std::cout << "I am a QTPOLYGON !!" << std::endl;
  }
}
