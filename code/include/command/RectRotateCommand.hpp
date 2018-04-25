#ifndef RECTROTATECOMMAND_HPP
#define RECTROTATECOMMAND_HPP

#include "CommandInterface.hpp"
#include "Rectangle.hpp"

namespace command
{
  class RectRotateCommand : public CommandInterface
  {
  public:
    RectRotateCommand (shape::Rectangle* rect, double angle);
    ~RectRotateCommand ();

    void execute ();

    void undo ();

  private:
    shape::Rectangle* m_rect;
    double m_angle;
    shape::Memento<shape::Rectangle> m_mem;
  };
}
#endif /* !defined(RECTROTATECOMMAND_HPP) */
