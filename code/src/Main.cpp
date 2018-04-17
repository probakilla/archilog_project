#include "Bridge.hpp"
#include "QtWindowFactory.hpp"

#include <QApplication>

int main (int argc, char** argv)
{
  QApplication app (argc, argv);

  widget::QtWindowFactory factory;
  widget::Bridge b (&factory);
  shape::Rectangle rect (shape::Point (250.0, 250.0));
  shape::Polygon poly;
  b.draw_rectangle (rect);
  b.draw_polygon (poly);
  b.show ();

  return app.exec ();
}
