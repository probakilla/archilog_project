#ifndef POLYGONCOLOR_HPP
#define POLYGONCOLOR_HPP

#include "CommandInterface.hpp"
#include "Polygon.hpp"

namespace shape
{
  class PolygonColor : public CommandInterface
  {
  public:
    PolygonColor (Polygon* poly, hex color);
    ~PolygonColor ();

    void execute ();

    void undo ();

  private:
    Polygon* _poly;
    hex _color;
    Memento<Polygon> _mem;
  };
}
#endif /* !defined(POLYGONCOLOR_HPP) */
