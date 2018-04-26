#include "PolyColorCommand.hpp"

namespace command
{
  PolyColorCommand::PolyColorCommand (shape::Polygon* poly, shape::hex color) :
   m_poly (poly), m_color (color)
  {}

  PolyColorCommand::~PolyColorCommand () {}

  void PolyColorCommand::execute ()
  {
    m_mem = m_poly->create_memento ();
    m_poly->set_color (m_color);
    m_poly->notify ();
  }

  void PolyColorCommand::undo ()
  {
    m_poly->set_memento (m_mem);
    m_poly->notify ();
  }
}
