#include "RectHeightCommand.hpp"
namespace shape
{
  RectHeightCommand::RectHeightCommand (Rectangle* rect, double height) :
   m_rect (rect), m_height (height)
  {}

  RectHeightCommand::~RectHeightCommand () {}

  void RectHeightCommand::execute ()
  {
    m_mem = m_rect->create_memento ();
    m_rect->set_height (m_height);
  }

  void RectHeightCommand::undo () { m_rect->set_memento (m_mem); }
}
