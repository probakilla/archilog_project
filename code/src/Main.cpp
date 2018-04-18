#include "Bridge.hpp"
#include "QtWindowFactory.hpp"

#include <QApplication>
#include <iostream>

int main (int argc, char** argv)
{
  QApplication app (argc, argv);

  widget::QtWindowFactory factory;
  widget::Bridge b (&factory);
  shape::Rectangle rect (shape::Point (50.0, 50.0), 50.0, 50.0);
  shape::Rectangle rect2 (shape::Point (-50.0, -50.0), 50.0, 50.0);
  b.draw_rectangle (rect);
  b.draw_rectangle (rect2);
  b.show ();

  return app.exec ();
}
