#include "AbstractShape.hpp"

namespace model
{
  AbstractShape::AbstractShape (Point pos) :
   m_position (pos), m_rotation_center (pos)
  {}
}
