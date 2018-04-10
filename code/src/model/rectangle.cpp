#include "rectangle.hpp"

namespace model
{
  rectangle::rectangle (point pos, double height, double width,
                        double rounding) :
   abstract_shape (pos),
   m_height (height), m_width (width), m_rounding_coeff (rounding)
  {}
}
