#include "QtRectangle.hpp"

#include "AbstractShape.hpp"
#include "QtDisplay.hpp"

#include <QMenu>
#include <QRectF>

namespace widget
{
  QtRectangle::QtRectangle (shape::Rectangle* rect, QWidget* parent) :
   QGraphicsRectItem (rect->get_position ().x (), rect->get_position ().y (),
                      rect->get_width (), rect->get_height ()),
   m_parent (parent), m_rect (rect)
  {
    setFlags (ItemIsMovable | ItemIsFocusable | ItemIsSelectable |
              ItemSendsGeometryChanges);
    m_menu = new QMenu (parent);
    this->setTransformOriginPoint (QPoint (
     m_rect->get_rotation_center ().x (), m_rect->get_rotation_center ().y ()));
    // Adjust the position.
    setPos (x () - rect->get_width () / 2, y () - rect->get_height () / 2);
  }

  QtRectangle::~QtRectangle () {}

  QMenu* QtRectangle::get_menu () const { return m_menu; }

  shape::Rectangle* QtRectangle::get_rect () const { return m_rect; }

  void QtRectangle::update_shape ()
  {
    QRectF tmp (m_rect->get_position ().x (), m_rect->get_position ().y (),
                m_rect->get_width (), m_rect->get_height ());
    this->setRect (tmp);
    this->setTransformOriginPoint (m_rect->get_rotation_center ().x (),
                                   m_rect->get_rotation_center ().y ());
    this->setBrush (QColor (m_rect->get_color ()));
    this->setRotation (m_rect->get_rotation ());
    this->update ();
  }

  void QtRectangle::contextMenuEvent (QGraphicsSceneContextMenuEvent* event)
  {
    if (event->reason () == QGraphicsSceneContextMenuEvent::Mouse)
    {
      QtDisplay::cur_rect = this;
      m_menu->exec (event->screenPos ());
    }
  }
}
