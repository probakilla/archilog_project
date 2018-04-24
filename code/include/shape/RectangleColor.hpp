#ifndef RECTANGLECOLOR_HPP
#define RECTANGLECOLOR_HPP

#include "CommandInterface.hpp"
#include "Rectangle.hpp"

namespace shape
{
  class RectangleColor : public CommandInterface
  {
  public:
    RectangleColor (Rectangle* poly, hex color);
    ~RectangleColor ();

    void execute ();

    void undo ();

  private:
    Rectangle* _poly;
    hex _color;
    Memento<Rectangle>* _mem;
  };
}
#endif /* !defined(RECTANGLECOLOR_HPP) */
