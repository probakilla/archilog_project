#ifndef QTRECTANGLE_HPP
#define QTRECTANGLE_HPP

#include "Rectangle.hpp"

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

namespace widget
{
  class QtRectangle : public QGraphicsRectItem
  {
  public:
    QtRectangle (shape::Rectangle rect);
    ~QtRectangle ();

    void contextMenuEvent (QGraphicsSceneContextMenuEvent* event);

  private:
    shape::Rectangle m_rect;
  };
}

#endif // !defined QTRECTANGLE_HPP
