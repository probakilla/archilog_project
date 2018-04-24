#ifndef POLYCOLORCOMMAND_HPP
#define POLYCOLORCOMMAND_HPP

#include "CommandInterface.hpp"
#include "Polygon.hpp"

namespace shape
{
  class PolyColorCommand : public CommandInterface
  {
  public:
    PolyColorCommand (Polygon* poly, hex color);
    ~PolyColorCommand ();

    void execute ();

    void undo ();

  private:
    Polygon* m_poly;
    hex m_color;
    Memento<Polygon> m_mem;
  };
}
#endif /* !defined(POLYCOLORCOMMAND_HPP) */
