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

    void mousePressEvent (QGraphicsSceneMouseEvent* mouseEvent);
  };
}
#endif /* !defined(QTMAINSCENE_HPP) */
