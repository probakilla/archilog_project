#include "QtWindowFactory.hpp"
#include "QtWindow.hpp"

namespace widget
{
  QtWindowFactory::QtWindowFactory () {}

  WindowInterface* QtWindowFactory::create_window ()
  {
    return new QtWindow;
  }
}
