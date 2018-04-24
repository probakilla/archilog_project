#include "PolyColorCommand.hpp"
namespace shape
{
  PolyColorCommand::PolyColorCommand (Polygon* poly, hex color) :
   m_poly (poly), m_color (color)
  {}
  PolyColorCommand::~PolyColorCommand () {}

  void PolyColorCommand::execute ()
  {
    m_mem = m_poly->create_memento ();
    m_poly->set_color (m_color);
  }

  void PolyColorCommand::undo () { m_poly->set_memento (m_mem); }
}
