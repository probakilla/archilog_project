#ifndef RECTANGLECOLOR_HPP
#define RECTANGLECOLOR_HPP

#include "CommandInterface.hpp"
#include "Rectangle.hpp"

namespace shape
{
  class RectColorCommand : public CommandInterface
  {
  public:
    RectColorCommand (Rectangle* rect, hex color);
    ~RectColorCommand ();

    void execute ();

    void undo ();

  private:
    Rectangle* m_rect;
    hex m_color;
    Memento<Rectangle> m_mem;
  };
}
#endif /* !defined(RECTANGLECOLOR_HPP) */
