#include "Window.hpp"

namespace widget
{
  Window::Window (WindowFactoryInterface* factory)
  {
    m_imp = factory->create_window ();
  }

  Window::~Window ()
  {
    delete m_imp;
  }

  void Window::show ()
  {
    m_imp->show ();
  }
}
