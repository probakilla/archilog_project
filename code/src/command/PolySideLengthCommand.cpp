#include "PolySideLengthCommand.hpp"
namespace command
{
  PolySideLengthCommand::PolySideLengthCommand (shape::Polygon* poly, double side_length) :
   m_poly (poly), m_side_length (side_length)
  {}

  PolySideLengthCommand::~PolySideLengthCommand () {}

  void PolySideLengthCommand::execute ()
  {
    m_mem = m_poly->create_memento ();
    m_poly->set_side_length (m_side_length);
  }

  void PolySideLengthCommand::undo () { m_poly->set_memento (m_mem); }
}
