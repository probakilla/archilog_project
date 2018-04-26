#include "RectRotateCommand.hpp"

namespace command
{
  RectRotateCommand::RectRotateCommand (shape::Rectangle* rect, double angle) :
   m_rect (rect), m_angle (angle)
  {}

  RectRotateCommand::~RectRotateCommand () {}

  void RectRotateCommand::execute ()
  {
    m_mem = m_rect->create_memento ();
    m_rect->set_rotation (m_angle);
    m_rect->notify ();
  }

  void RectRotateCommand::undo ()
  {
    m_rect->set_memento (m_mem);
    m_rect->notify ();
  }
}
