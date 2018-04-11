#include "Rectangle.hpp"

namespace shape
{
  Rectangle::Rectangle (double height, double width, double rounding) :
   AbstractShape (), m_height (height), m_width (width),
   m_rounding_coeff (rounding)
  {}

  Rectangle::Rectangle (const Point& pos, double height, double width,
                        double rounding) :
   AbstractShape (pos),
   m_height (height), m_width (width), m_rounding_coeff (rounding)
  {}
}
