#include "QtPolygon.hpp"

#include <QMenu>
#include <QPolygonF>
#include <cmath>

#define _USE_MATH_DEFINES

namespace widget
{
  static QPolygonF get_point (shape::Polygon poly)
  {
    QVector<QPointF> points;
    int n = poly.get_nb_sides ();
    // Radius of the exterior circle
    // ref : https://www.mathopenref.com/polygonradius.html
    double rad = (poly.get_side_length () / (2 * (sin (180 / n * M_PI / 180))));

    // Searching all points coordinates
    for (int i = 0; i < n; ++i)
    {
      points.push_back (
       QPointF (rad * cos (2 * M_PI * i / n), rad * sin (2 * M_PI * i / n)));
    }

    // Adusting position
    shape::Point pos = poly.get_position ();
    for (int i = 0; i < n; ++i)
    {
      points[i].setX (points[i].rx () + pos.x ());
      points[i].setY (points[i].ry () + pos.y ());
    }
    return QPolygonF (points);
  }

  QtPolygon::QtPolygon (shape::Polygon poly) :
   QGraphicsPolygonItem (get_point (poly)), m_poly (poly)
  {}

  QtPolygon::~QtPolygon () {}

  void QtPolygon::contextMenuEvent (QGraphicsSceneContextMenuEvent* event)
  {
    if (event->reason() == QGraphicsSceneContextMenuEvent::Mouse)
    {
      QMenu menu;
      menu.addAction ("Edit color");
      menu.addAction ("Edit rotation center");
      menu.addAction ("Edit number of sides");
      menu.addAction ("Edit side length");
      menu.exec (event->screenPos ());
    }
  }
}
