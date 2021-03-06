#ifndef POLYNBSIDESCOMMAND_HPP
#define POLYNBSIDESCOMMAND_HPP

#include "CommandInterface.hpp"
#include "Polygon.hpp"

namespace command
{
  class PolyNbSidesCommand : public CommandInterface
  {
  public:
    PolyNbSidesCommand (shape::Polygon* poly, int nb_sides);
    ~PolyNbSidesCommand ();

    void execute ();

    void undo ();

  private:
    shape::Polygon* m_poly;
    int m_nb_sides;
    shape::Memento<shape::Polygon> m_mem;
  };
}
#endif /* !defined(POLYNBSIDESCOMMAND_HPP) */
