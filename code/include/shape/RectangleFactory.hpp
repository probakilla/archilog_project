#ifndef RECTANGLEFACTORY_HPP
#define RECTANGLEFACTORY_HPP

#include "ShapeFactoryInterface.hpp"

namespace shape
{
  class RectangleFactory : public ShapeFactoryInterface
  {
  public:
    RectangleFactory ();
    ~RectangleFactory ();
  };
}
#endif /* !defined(RECTANGLEFACTORY_HPP) */
