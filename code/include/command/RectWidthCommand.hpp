#ifndef RECTWIDTHCOMMAND_HPP
#define RECTWIDTHCOMMAND_HPP

#include "CommandInterface.hpp"
#include "Rectangle.hpp"

namespace command
{
  class RectWidthCommand : public CommandInterface
  {
  public:
    RectWidthCommand (shape::Rectangle* rect, double width);
    ~RectWidthCommand ();

    void execute ();

    void undo ();

  private:
    shape::Rectangle* m_rect;
    double m_width;
    shape::Memento<shape::Rectangle> m_mem;
  };
}
#endif /* !defined(RECTWIDTHCOMMAND_HPP) */
