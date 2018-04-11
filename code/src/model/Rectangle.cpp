#include "Rectangle.hpp"

namespace model
{
  Rectangle::Rectangle (Point pos, double height, double width,
                        double rounding) :
   AbstractShape (pos),
   m_height (height), m_width (width), m_rounding_coeff (rounding)
  {}
}
