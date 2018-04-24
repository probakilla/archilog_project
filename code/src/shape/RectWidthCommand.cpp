#include "RectWidthCommand.hpp"
namespace shape
{
  RectWidthCommand::RectWidthCommand (Rectangle* rect, double width) :
   m_rect (rect), m_width (width)
  {}

  RectWidthCommand::~RectWidthCommand () {}

  void RectWidthCommand::execute ()
  {
    m_mem = m_rect->create_memento ();
    m_rect->set_width (m_width);
  }

  void RectWidthCommand::undo () { m_rect->set_memento (m_mem); }
}
