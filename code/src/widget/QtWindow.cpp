#include "QtWindow.hpp"

namespace widget
{
  QtWindow::QtWindow () { m_window = new QtDisplay; }

  QtWindow::~QtWindow () { delete m_window; }

  void QtWindow::show () { m_window->show (); }

  void QtWindow::draw_rectangle (shape::Rectangle& rect)
  {
    m_window->draw_rectangle (rect);
  }

  void QtWindow::draw_polygon (shape::Polygon& poly)
  {
    m_window->draw_polygon (poly);
  }
}
