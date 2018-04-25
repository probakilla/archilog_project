#include "PolyRotateCommand.hpp"

namespace command
{
  PolyRotateCommand::PolyRotateCommand (shape::Polygon* poly, double angle) :
   m_poly (poly), m_angle (angle)
  {}

  PolyRotateCommand::~PolyRotateCommand () {}

  void PolyRotateCommand::execute ()
  {
    m_mem = m_poly->create_memento ();
    m_poly->set_rotation (m_angle);
  }

  void PolyRotateCommand::undo () { m_poly->set_memento (m_mem); }
}
