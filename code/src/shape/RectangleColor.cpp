#include "RectangleColor.hpp"
namespace shape
{
  RectangleColor::RectangleColor (Rectangle* poly, hex color) :
   _poly (poly), _color (color), _mem (NULL)
  {}
  RectangleColor::~RectangleColor () {}

  void RectangleColor::execute ()
  {
    *_mem = _poly->create_memento ();
    _poly->set_color (_color);
  }

  void RectangleColor::undo ()
  {
    if (_mem != NULL)
      _poly->set_memento (*_mem);
  }
}
