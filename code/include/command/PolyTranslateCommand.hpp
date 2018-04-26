#ifndef POLYTRANSLATECOMMAND_HPP
#define POLYTRANSLATECOMMAND_HPP

#include "CommandInterface.hpp"
#include "Polygon.hpp"

namespace command
{
  class PolyTranslateCommand : public CommandInterface
  {
  public:
    PolyTranslateCommand (shape::Polygon* poly, double dx, double dy);
    ~PolyTranslateCommand ();

    void execute ();

    void undo ();

  private:
    shape::Polygon* m_poly;
    double m_dx;
    double m_dy;
    shape::Memento<shape::Polygon> m_mem;
  };
}
#endif /* !defined(POLYTRANSLATECOMMAND_HPP) */
