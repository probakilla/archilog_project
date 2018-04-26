#include "PolyTranslateCommand.hpp"

namespace command
{
  PolyTranslateCommand::PolyTranslateCommand (shape::Polygon* poly, double dx,
                                              double dy) :
   m_poly (poly),
   m_dx (dx), m_dy (dy)
  {}

  PolyTranslateCommand::~PolyTranslateCommand () {}

  void PolyTranslateCommand::execute ()
  {
    m_mem = m_poly->create_memento ();
    m_poly->translate (m_dx, m_dy);
    m_poly->notify ();
  }

  void PolyTranslateCommand::undo ()
  {
    m_poly->set_memento (m_mem);
    m_poly->notify ();
  }
}
