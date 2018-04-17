#include "QtMainWindow.hpp"

namespace widget
{
  QtMainWindow::QtMainWindow ()
  {
    m_window = new QtWindow;
  }

  QtMainWindow::~QtMainWindow ()
  {
    delete m_window;
  }

  void QtMainWindow::show ()
  {
    m_window->show ();
  }
}
