#ifndef QTPOLYGON_HPP
#define QTPOLYGON_HPP

#include "Polygon.hpp"

#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>

namespace widget
{
  class QtPolygon : public QGraphicsPolygonItem
  {
  public:
    QtPolygon (shape::Polygon poly);
    ~QtPolygon ();

    void contextMenuEvent (QGraphicsSceneContextMenuEvent* event);

  private:
    shape::Polygon m_poly;
  };
}

#endif // !defined QTPOLYGON_HPP
