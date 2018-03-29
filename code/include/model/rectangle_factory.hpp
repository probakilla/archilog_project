#ifndef RECTANGLE_FACTORY_HPP
#define RECTANGLE_FACTORY_HPP

#include "shape_factory_interface.hpp"

namespace model
{
  class rectangle_factory : public shape_factory_interface
  {
  public:
    rectangle_factory ();
    ~rectangle_factory ();
  };
}
#endif /* !defined(RECTANGLE_FACTORY_HPP) */
