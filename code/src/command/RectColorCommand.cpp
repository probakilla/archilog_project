#include "RectColorCommand.hpp"

namespace command
{
  RectColorCommand::RectColorCommand (shape::Rectangle* rect,
                                      shape::hex color) :
   m_rect (rect),
   m_color (color)
  {}

  RectColorCommand::~RectColorCommand () {}

  void RectColorCommand::execute ()
  {
    m_mem = m_rect->create_memento ();
    m_rect->set_color (m_color);
    m_rect->notify ();
  }

  void RectColorCommand::undo ()
  {
    m_rect->set_memento (m_mem);
    m_rect->notify ();
  }
}
