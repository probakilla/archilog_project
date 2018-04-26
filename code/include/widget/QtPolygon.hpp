#ifndef QTPOLYGON_HPP
#define QTPOLYGON_HPP

#include "Polygon.hpp"

#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>

namespace widget
{
  class QtPolygon : public QGraphicsPolygonItem, public ObserverInterface
  {
  public:
    QtPolygon (shape::Polygon* poly, QWidget* parent);
    ~QtPolygon ();

    shape::Polygon* get_poly () const;

    QMenu* get_menu () const;

    void update_shape ();

    void contextMenuEvent (QGraphicsSceneContextMenuEvent* event);

  private:
    QWidget* m_parent;
    QMenu* m_menu;
    shape::Polygon* m_poly;
  };
}

#endif // !defined QTPOLYGON_HPP
