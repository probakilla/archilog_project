#ifndef POLYSIDELENGTHCOMMAND_HPP
#define POLYSIDELENGTHCOMMAND_HPP

#include "CommandInterface.hpp"
#include "Polygon.hpp"

namespace command
{
  class PolySideLengthCommand : public CommandInterface
  {
  public:
    PolySideLengthCommand (shape::Polygon* poly, double side_length);
    ~PolySideLengthCommand ();

    void execute ();

    void undo ();

  private:
    shape::Polygon* m_poly;
    double m_side_length;
    shape::Memento<shape::Polygon> m_mem;
  };
}
#endif /* !defined(POLYSIDELENGTHCOMMAND_HPP) */
