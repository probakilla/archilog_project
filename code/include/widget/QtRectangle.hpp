#ifndef QTRECTANGLE_HPP
#define QTRECTANGLE_HPP

#include "Rectangle.hpp"

#include <QAction>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QString>
#include <QMenu>

#define MAX_VALUE 1024.0

namespace widget
{
  class QtRectangle : public QGraphicsRectItem
  {
  public:
    QtRectangle (shape::Rectangle* rect, QWidget* parent = 0);
    ~QtRectangle ();

    QMenu* get_menu () const;

    shape::Rectangle* get_rect () const;

    void update_shape ();

    //!< The context menu of the shape, open with right click
    void contextMenuEvent (QGraphicsSceneContextMenuEvent* event);

  private:
    QMenu* m_menu;
    QWidget* m_parent;
    shape::Rectangle* m_rect; //!< The shape::Rectangle corresponding
  };
}

#endif // !defined QTRECTANGLE_HPP
