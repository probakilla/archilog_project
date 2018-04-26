#include "QtPolygon.hpp"

#include "QtDisplay.hpp"

#include <QPointF>
#include <QPolygonF>
#include <cmath>

#define _USE_MATH_DEFINES

#define MIN_VALUE 1.0
#define DECIMALS 2

namespace widget
{
  static QPolygonF get_point (shape::Polygon* poly)
  {
    QVector<QPointF> points;
    int n = poly->get_nb_sides ();
    // Radius of the exterior circle
    // ref : https://www.mathopenref.com/polygonradius.html
    double rad =
     (poly->get_side_length () / (2 * (sin (180 / n * M_PI / 180))));

    // Searching all points coordinates
    for (int i = 0; i < n; ++i)
    {
      points.push_back (
       QPointF (rad * cos (2 * M_PI * i / n), rad * sin (2 * M_PI * i / n)));
    }

    // Adusting position
    shape::Point pos = poly->get_position ();
    for (int i = 0; i < n; ++i)
    {
      points[i].setX (points[i].rx () + pos.x ());
      points[i].setY (points[i].ry () + pos.y ());
    }
    return QPolygonF (points);
  }

  QtPolygon::QtPolygon (shape::Polygon* poly, QWidget* parent) :
   QGraphicsPolygonItem (get_point (poly)), m_parent (parent), m_poly (poly)
  {
    setFlags (ItemIsMovable | ItemIsFocusable | ItemIsSelectable |
              ItemSendsGeometryChanges);
    this->setTransformOriginPoint (poly->get_rotation_center ().x (),
                                   poly->get_rotation_center ().y ());
    m_menu = new QMenu (parent);
  }

  QtPolygon::~QtPolygon () {}

  shape::Polygon* QtPolygon::get_poly () const { return m_poly; }

  QMenu* QtPolygon::get_menu () const { return m_menu; }

  void QtPolygon::update_shape ()
  {
    QPolygonF tmp (get_point (m_poly));
    this->setPolygon (tmp);
    this->setTransformOriginPoint (m_poly->get_rotation_center ().x (),
                                   m_poly->get_rotation_center ().y ());
    this->setBrush (QColor (m_poly->get_color ()));
    this->setRotation (m_poly->get_rotation ());
    this->update ();
  }

  void QtPolygon::contextMenuEvent (QGraphicsSceneContextMenuEvent* event)
  {
    if (event->reason () == QGraphicsSceneContextMenuEvent::Mouse)
    {
      QtDisplay::cur_poly = this;
      m_menu->exec (event->screenPos ());
    }
  }
}
