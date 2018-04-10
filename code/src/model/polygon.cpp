#include "polygon.hpp"

namespace model
{
  polygon::polygon (point pos, int nb_sides, double side_length) :
   abstract_shape (pos), m_nb_sides (nb_sides), m_side_length (side_length)
  {}
}
