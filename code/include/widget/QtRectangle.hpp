#ifndef QTRECTANGLE_HPP
#define QTRECTANGLE_HPP

#include "Rectangle.hpp"
#include "ObserverInterface.hpp"

#include <QAction>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>
#include <QString>

namespace widget
{
  class QtRectangle : public QGraphicsRectItem, public ObserverInterface
  {
  public:
    QtRectangle (shape::Rectangle* rect, QWidget* parent = 0);
    ~QtRectangle ();

    //!< Getter on QtRectangle::m_menu
    QMenu* get_menu () const;

    //!< Getter on QtRectangle::m_rect
    shape::Rectangle* get_rect () const;

    //!< Update the shape data
    void update_shape ();

    //!< The context menu of the shape, open with right click
    void contextMenuEvent (QGraphicsSceneContextMenuEvent* event);

    void mouseReleaseEvent (QGraphicsSceneMouseEvent * event);

    void update_position ();

  private:
    QMenu* m_menu;
    QWidget* m_parent;
    shape::Rectangle* m_rect; //!< The shape::Rectangle corresponding
  };
}

#endif // !defined QTRECTANGLE_HPP
