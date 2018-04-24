#ifndef QTMAINSCENE_HPP
#define QTMAINSCENE_HPP

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

namespace widget
{
  class QtMainScene : public QGraphicsScene
  {
  public:
    QtMainScene (QObject* parent = 0);
    ~QtMainScene ();

    void mousePressEvent (QGraphicsSceneMouseEvent* mouseEvent) override;

    void mouseReleaseEvent (QGraphicsSceneMouseEvent* mouseEvent) override;

    void mouseMoveEvent (QGraphicsSceneMouseEvent* mouseEvent) override;

    void mouseDoubleClickEvent (QGraphicsSceneMouseEvent* mouseEvent) override;
  };
}
#endif /* !defined(QTMAINSCENE_HPP) */
