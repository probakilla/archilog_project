#include "PolyNbSidesCommand.hpp"

namespace command
{
  PolyNbSidesCommand::PolyNbSidesCommand (shape::Polygon* poly,
                                          double nb_sides) :
   m_poly (poly),
   m_nb_sides (nb_sides)
  {}

  PolyNbSidesCommand::~PolyNbSidesCommand () {}

  void PolyNbSidesCommand::execute ()
  {
    m_mem = m_poly->create_memento ();
    m_poly->set_nb_sides (m_nb_sides);
    m_poly->notify ();
  }

  void PolyNbSidesCommand::undo ()
  {
    m_poly->set_memento (m_mem);
    m_poly->notify ();
  }
}
