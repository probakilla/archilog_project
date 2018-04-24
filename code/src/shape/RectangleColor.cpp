#include "RectangleColor.hpp"
namespace shape
{
  RectangleColor::RectangleColor (Rectangle* rect, hex color) :
   _rect (rect), _color (color)
  {}
  RectangleColor::~RectangleColor () {}

  void RectangleColor::execute ()
  {
    _mem = _rect->create_memento ();
    _rect->set_color (_color);
  }

  void RectangleColor::undo () { _rect->set_memento (_mem); }
}
