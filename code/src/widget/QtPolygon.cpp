#include "QtPolygon.hpp"

#include "AllCommands.hpp"
#include "PolyTranslateCommand.hpp"
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
    return QPolygonF (points);
  }

  QtPolygon::QtPolygon (shape::Polygon* poly, QWidget* parent) :
   QGraphicsPolygonItem (get_point (poly)), m_parent (parent), m_poly (poly)
  {
    // Adjusting position.
    this->setX (m_poly->get_position ().x ());
    this->setY (m_poly->get_position ().y ());

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
    //QPolygonF tmp (get_point (m_poly));
    //this->setPolygon (tmp);
    this->setX (m_poly->get_position ().x ());
    this->setY (m_poly->get_position ().y ());
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

  void QtPolygon::mouseReleaseEvent (QGraphicsSceneMouseEvent* event)
  {
    QGraphicsPolygonItem::mouseReleaseEvent (event);
    if (event->button () == Qt::LeftButton)
      update_position ();
  }

  void QtPolygon::update_position ()
  {
    shape::Point pos = m_poly->get_position ();
    double dx = x () - pos.x ();
    double dy = y () - pos.y ();
    shape::AllCommands* cmd_list = shape::AllCommands::get_instance ();
    cmd_list->add_undoable (new command::PolyTranslateCommand (m_poly, dx, dy));
  }
}
