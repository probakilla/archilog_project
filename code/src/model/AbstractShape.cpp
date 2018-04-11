#include "AbstractShape.hpp"

namespace model
{
  AbstractShape::AbstractShape (point pos) :
   m_position (pos), m_rotation_center (pos)
  {}
}
