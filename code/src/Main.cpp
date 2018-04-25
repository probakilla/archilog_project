#include "Bridge.hpp"
#include "QtWindowFactory.hpp"

#include <QApplication>
#include <iostream>

int main (int argc, char** argv)
{
  QApplication app (argc, argv);

  widget::QtWindowFactory factory;
  widget::Bridge b (&factory);
  shape::Rectangle rect (shape::Point (-150.0, -150.0), 15.0, 15.0);
  rect.set_color (0xbbbbbb);
  shape::Polygon poly (shape::Point (100, 100), 7, 10.0);
  b.draw_rectangle (rect);
  b.draw_polygon (poly);
  b.show ();

  return app.exec ();
}
