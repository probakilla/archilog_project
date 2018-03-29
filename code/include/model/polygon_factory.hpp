#ifndef POLYGON_FACTORY_HPP
#define POLYGON_FACTORY_HPP

#include "shape_factory_interface.hpp"

namespace model
{
  class polygon_factory : public shape_factory_interface
  {
  public:
    polygon_factory ();
    ~polygon_factory ();
  };
}
#endif /* !defined(POLYGON_FACTORY_HPP) */
