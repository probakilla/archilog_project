#include "RectTranslateCommand.hpp"

namespace command
{
  RectTranslateCommand::RectTranslateCommand (shape::Rectangle* rect, double dx,
                                              double dy) :
   m_rect (rect),
   m_dx (dx), m_dy (dy)
  {}

  RectTranslateCommand::~RectTranslateCommand () {}

  void RectTranslateCommand::execute ()
  {
    m_mem = m_rect->create_memento ();
    m_rect->translate (m_dx, m_dy);
    m_rect->notify ();
  }

  void RectTranslateCommand::undo ()
  {
    m_rect->set_memento (m_mem);
    m_rect->notify ();
  }
}
