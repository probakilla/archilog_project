#include "QtWindowFactory.hpp"
#include "QtMainWindow.hpp"

namespace widget
{
  QtWindowFactory::QtWindowFactory () {}

  WindowInterface* QtWindowFactory::create_window ()
  {
    return new QtMainWindow;
  }
}
