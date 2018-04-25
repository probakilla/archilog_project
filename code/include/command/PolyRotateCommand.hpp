#ifndef POLYROTATECOMMAND_HPP
#define POLYROTATECOMMAND_HPP

#include "CommandInterface.hpp"
#include "Polygon.hpp"

namespace command
{
  class PolyRotateCommand : public CommandInterface
  {
  public:
    PolyRotateCommand (shape::Polygon* poly, double angle);
    ~PolyRotateCommand ();

    void execute ();

    void undo ();

  private:
    shape::Polygon* m_poly;
    double m_angle;
    shape::Memento<shape::Polygon> m_mem;
  };
}
#endif /* !defined(POLYROTATECOMMAND_HPP) */
