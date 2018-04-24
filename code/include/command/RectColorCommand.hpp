#ifndef RECTANGLECOLOR_HPP
#define RECTANGLECOLOR_HPP

#include "CommandInterface.hpp"
#include "Rectangle.hpp"

namespace command
{
  class RectColorCommand : public CommandInterface
  {
  public:
    RectColorCommand (shape::Rectangle* rect, shape::hex color);
    ~RectColorCommand ();

    void execute ();

    void undo ();

  private:
    shape::Rectangle* m_rect;
    shape::hex m_color;
    shape::Memento<shape::Rectangle> m_mem;
  };
}
#endif /* !defined(RECTANGLECOLOR_HPP) */
