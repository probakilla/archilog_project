#include "QtRectangle.hpp"

#include "AbstractShape.hpp"
#include "AllCommands.hpp"
#include "QtDisplay.hpp"
#include "RectTranslateCommand.hpp"

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
    setPos (rect->get_position ().x (), rect->get_position ().y ());
  }

  QtRectangle::~QtRectangle () {}

  QMenu* QtRectangle::get_menu () const { return m_menu; }

  shape::Rectangle* QtRectangle::get_rect () const { return m_rect; }

  void QtRectangle::update_shape ()
  {
    QRectF tmp (rect ().x (), rect ().y (), m_rect->get_width (),
                m_rect->get_height ());
    this->setRect (tmp);
    this->setX (m_rect->get_position ().x ());
    this->setY (m_rect->get_position ().y ());
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

  void QtRectangle::mouseReleaseEvent (QGraphicsSceneMouseEvent* event)
  {
    QGraphicsRectItem::mouseReleaseEvent (event);
    if (event->button () == Qt::LeftButton)
      update_position ();
  }

  void QtRectangle::update_position ()
  {
    shape::Point pos = m_rect->get_position ();
    double dx = x () - pos.x ();
    double dy = y () - pos.y ();
    shape::AllCommands* cmd_list = shape::AllCommands::get_instance ();
    cmd_list->add_undoable (
     new command::RectTranslateCommand (m_rect, dx, dy));
  }
}
