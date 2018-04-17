#include "Bridge.hpp"
#include "QtWindowFactory.hpp"

#include <QApplication>

int main (int argc, char** argv)
{
  QApplication app (argc, argv);

  widget::QtWindowFactory factory;
  widget::Bridge b (&factory);
  shape::Rectangle rect;
  b.draw_rectangle (rect);
  b.show ();

  return app.exec ();
}
