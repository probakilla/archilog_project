#include "abstract_shape.hpp"

namespace model
{
  abstract_shape::abstract_shape (point pos) :
   m_position (pos), m_rotation_center (pos)
  {}
}
