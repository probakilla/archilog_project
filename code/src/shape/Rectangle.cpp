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

  double Rectangle::get_height () const { return m_height; }

  double Rectangle::get_width () const { return m_width; }

  double Rectangle::get_rounding_coeff () const { return m_rounding_coeff; }

  Rectangle& Rectangle::operator= (const Rectangle& rec)
  {
    AbstractShape::operator= (rec);
    m_height = rec.m_height;
    m_width = rec.m_width;
    m_rounding_coeff = rec.m_rounding_coeff;
    return *this;
  }

  bool Rectangle::operator== (const ShapeInterface& shape)
  {
    if (!AbstractShape::operator== (shape))
      return false;
    if (m_height == static_cast<const Rectangle&> (shape).m_height)
      if (m_width == static_cast<const Rectangle&> (shape).m_width)
        if (m_rounding_coeff ==
            static_cast<const Rectangle&> (shape).m_rounding_coeff)
          return true;
    return false;
  }
}
