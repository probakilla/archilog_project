#include "QtRectangle.hpp"

#include <iostream>

namespace shape
{
  QtRectangle::QtRectangle (double height, double width, double rounding) :
   Rectangle (height, width, rounding)
  {}

  QtRectangle::QtRectangle (const Point& pos, double height, double width,
                            double rounding) :
   Rectangle (pos, height, width, rounding)
  {}

  void QtRectangle::draw ()
  {
    // Temporary
    std::cout << "I am a QTRECTANGLE !!" << std::endl;
  }
}
