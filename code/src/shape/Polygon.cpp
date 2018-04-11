#include "Polygon.hpp"

namespace shape
{
  Polygon::Polygon (const Point& pos, int nb_sides, double side_length) :
   AbstractShape (pos), m_nb_sides (nb_sides), m_side_length (side_length)
  {}
}
