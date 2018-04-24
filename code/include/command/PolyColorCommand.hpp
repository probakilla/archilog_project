#ifndef POLYCOLORCOMMAND_HPP
#define POLYCOLORCOMMAND_HPP

#include "CommandInterface.hpp"
#include "Polygon.hpp"

namespace command
{
  class PolyColorCommand : public CommandInterface
  {
  public:
    PolyColorCommand (shape::Polygon* poly, shape::hex color);
    ~PolyColorCommand ();

    void execute ();

    void undo ();

  private:
    shape::Polygon* m_poly;
    shape::hex m_color;
    shape::Memento<shape::Polygon> m_mem;
  };
}
#endif /* !defined(POLYCOLORCOMMAND_HPP) */
