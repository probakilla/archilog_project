#include "QtMainScene.hpp"

#include <QColorDialog>
#include <QGraphicsItem>
#include <QList>
#include <QWidget>
#include <iostream>

namespace widget
{
  QtMainScene::QtMainScene (QObject* parent) : QGraphicsScene (parent) {}
  QtMainScene::~QtMainScene () {}

  void QtMainScene::mousePressEvent (QGraphicsSceneMouseEvent* mouseEvent)
  {
    mouseEvent->ignore ();
    QGraphicsScene::mousePressEvent (mouseEvent);
  }

  void QtMainScene::mouseReleaseEvent (QGraphicsSceneMouseEvent* mouseEvent)
  {
    mouseEvent->ignore ();
    QGraphicsScene::mouseReleaseEvent (mouseEvent);
  }

  void QtMainScene::mouseMoveEvent (QGraphicsSceneMouseEvent* mouseEvent)
  {
    QGraphicsScene::mouseMoveEvent (mouseEvent);
    mouseEvent->ignore ();
  }

  void QtMainScene::mouseDoubleClickEvent (QGraphicsSceneMouseEvent* mouseEvent)
  {
    QGraphicsScene::mouseDoubleClickEvent (mouseEvent);
    mouseEvent->ignore ();
  }
}
