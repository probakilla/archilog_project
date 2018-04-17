#include "QtWindowFactory.hpp"
#include "Window.hpp"

#include <QApplication>

int main (int argc, char** argv)
{
  QApplication app (argc, argv);

  widget::QtWindowFactory factory;
  widget::Window w (&factory);

  w.show ();

  return app.exec ();
}
