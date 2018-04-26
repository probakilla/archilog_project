#include "RectHeightCommand.hpp"

namespace command
{
  RectHeightCommand::RectHeightCommand (shape::Rectangle* rect, double height) :
   m_rect (rect), m_height (height)
  {}

  RectHeightCommand::~RectHeightCommand () {}

  void RectHeightCommand::execute ()
  {
    m_mem = m_rect->create_memento ();
    m_rect->set_height (m_height);
    m_rect->notify ();
  }

  void RectHeightCommand::undo ()
  {
    m_rect->set_memento (m_mem);
    m_rect->notify ();
  }
}
