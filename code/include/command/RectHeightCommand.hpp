#ifndef RECTHEIGHTCOMMAND_HPP
#define RECTHEIGHTCOMMAND_HPP

#include "CommandInterface.hpp"
#include "Rectangle.hpp"

namespace command
{
  class RectHeightCommand : public CommandInterface
  {
  public:
    RectHeightCommand (shape::Rectangle* rect, double height);
    ~RectHeightCommand ();

    void execute ();

    void undo ();

  private:
    shape::Rectangle* m_rect;
    double m_height;
    shape::Memento<shape::Rectangle> m_mem;
  };
}
#endif /* !defined(RECTHEIGHTCOMMAND_HPP) */
