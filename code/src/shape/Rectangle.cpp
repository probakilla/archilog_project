#include "Rectangle.hpp"

namespace shape
{
  Rectangle::Rectangle (Point pos, double height, double width,
                        double rounding) :
   AbstractShape (pos),
   m_height (height), m_width (width), m_rounding_coeff (rounding)
  {}
}
