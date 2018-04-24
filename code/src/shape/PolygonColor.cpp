#include "PolygonColor.hpp"
namespace shape
{
  PolygonColor::PolygonColor (Polygon* poly, hex color) :
   _poly (poly), _color (color), _mem (NULL)
  {}
  PolygonColor::~PolygonColor () {}

  void PolygonColor::execute ()
  {
    *_mem = _poly->create_memento ();
    _poly->set_color (_color);
  }

  void PolygonColor::undo ()
  {
    if (_mem != NULL)
      _poly->set_memento (*_mem);
  }
}
