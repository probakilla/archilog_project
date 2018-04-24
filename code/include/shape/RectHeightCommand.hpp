#ifndef RECTHEIGHTCOMMAND_HPP
#define RECTHEIGHTCOMMAND_HPP

#include "CommandInterface.hpp"
#include "Rectangle.hpp"

namespace shape
{
  class RectHeightCommand : public CommandInterface
  {
  public:
    RectHeightCommand (Rectangle* rect, double height);
    ~RectHeightCommand ();

    void execute ();

    void undo ();

  private:
    Rectangle* m_rect;
    double m_height;
    Memento<Rectangle> m_mem;
  };
}
#endif /* !defined(RECTHEIGHTCOMMAND_HPP) */
