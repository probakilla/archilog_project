#include "QtWindowFactory.hpp"
#include "Bridge.hpp"

#include <QApplication>

int main (int argc, char** argv)
{
  QApplication app (argc, argv);

  widget::QtWindowFactory factory;
  widget::Bridge b (&factory);

  b.show ();

  return app.exec ();
}
