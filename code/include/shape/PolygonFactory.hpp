#ifndef POLYGONFACTORY_HPP
#define POLYGONFACTORY_HPP

#include "ShapeFactoryInterface.hpp"

namespace shape
{
  class PolygonFactory : public ShapeFactoryInterface
  {
  public:
    PolygonFactory ();
    ~PolygonFactory ();
  };
}
#endif /* !defined(POLYGONFACTORY_HPP) */
