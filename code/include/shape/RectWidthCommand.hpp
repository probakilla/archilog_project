#ifndef RECTWIDTHCOMMAND_HPP
#define RECTWIDTHCOMMAND_HPP

#include "CommandInterface.hpp"
#include "Rectangle.hpp"

namespace shape
{
  class RectWidthCommand : public CommandInterface
  {
  public:
    RectWidthCommand (Rectangle* rect, double width);
    ~RectWidthCommand ();
		
    void execute ();

    void undo ();

  private:
    Rectangle* m_rect;
    double m_width;
    Memento<Rectangle> m_mem;
  };
}
#endif /* !defined(RECTWIDTHCOMMAND_HPP) */
