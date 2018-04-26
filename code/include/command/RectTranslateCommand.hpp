#ifndef RECTTRANSLATECOMMAND_HPP
#define RECTTRANSLATECOMMAND_HPP

#include "CommandInterface.hpp"
#include "Rectangle.hpp"

namespace command
{
  class RectTranslateCommand : public CommandInterface
  {
  public:
    RectTranslateCommand (shape::Rectangle* rect, double dx, double dy);
    ~RectTranslateCommand ();

    void execute ();

    void undo ();

  private:
    shape::Rectangle* m_rect;
    double m_dx;
    double m_dy;
    shape::Memento<shape::Rectangle> m_mem;
  };
}
#endif /* !defined(RECTTRANSLATECOMMAND_HPP) */
