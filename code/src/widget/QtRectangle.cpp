#include "QtRectangle.hpp"

#include <QAction>
#include <QColorDialog>
#include <QMenu>


namespace widget
{
  QtRectangle::QtRectangle (shape::Rectangle rect) :
   QGraphicsRectItem (rect.get_position ().x (), rect.get_position ().y (),
                      rect.get_width (), rect.get_height ()),
   m_rect (rect)
  {}

  QtRectangle::~QtRectangle () {}

  void QtRectangle::contextMenuEvent (QGraphicsSceneContextMenuEvent* event)
  {
    if (event->reason() == QGraphicsSceneContextMenuEvent::Mouse)
    {
      QMenu menu;
      menu.addAction ("Edit color");
      menu.addAction ("Edit rotation center");
      menu.addAction ("Edit height");
      menu.addAction ("Edit width");
      menu.addAction ("Edit rounding coefficient");
      menu.exec (event->screenPos ());
    }
  }
}
