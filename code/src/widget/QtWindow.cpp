#include "QtWindow.hpp"

namespace widget
{
  QtWindow::QtWindow ()
  {
    m_window = new QtDisplay;
  }

  QtWindow::~QtWindow ()
  {
    delete m_window;
  }

  void QtWindow::show ()
  {
    m_window->show ();
  }
}
