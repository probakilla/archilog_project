#include "Bridge.hpp"

namespace widget
{
  Bridge::Bridge (WindowFactoryInterface* factory)
  {
    m_imp = factory->create_window ();
  }

  Bridge::~Bridge () { delete m_imp; }

  void Bridge::show () { m_imp->show (); }

  void Bridge::draw_rectangle (shape::Rectangle& rect)
  {
    m_imp->draw_rectangle (rect);
  }

  void Bridge::draw_polygon (shape::Polygon& poly)
  {
    m_imp->draw_polygon (poly);
  }
}
