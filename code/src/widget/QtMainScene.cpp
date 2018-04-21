#include "QtMainScene.hpp"

#include <iostream>

namespace widget
{
  QtMainScene::QtMainScene (QObject* parent) : QGraphicsScene (parent) {}
  QtMainScene::~QtMainScene () {}

  void QtMainScene::mousePressEvent (QGraphicsSceneMouseEvent* mouseEvent)
  {
    if (mouseEvent->button () == Qt::RightButton)
      std::cout << "lol" << std::endl;
    else // Propagation of the event.
    {
      mouseEvent->ignore ();
      QGraphicsScene::mousePressEvent (mouseEvent);
    }
  }
  void QtMainScene::mouseReleaseEvent (QGraphicsSceneMouseEvent* mouseEvent)
  {
    if (mouseEvent->button () != Qt::RightButton)
    {
      mouseEvent->ignore ();
      QGraphicsScene::mouseReleaseEvent (mouseEvent);
    }
  }
  void QtMainScene::mouseMoveEvent (QGraphicsSceneMouseEvent* mouseEvent)
  {
    if (mouseEvent->button () != Qt::RightButton)
    {
      QGraphicsScene::mouseMoveEvent (mouseEvent);
      mouseEvent->ignore ();
    }
  }
  void QtMainScene::mouseDoubleClickEvent (QGraphicsSceneMouseEvent* mouseEvent)
  {
    if (mouseEvent->button () != Qt::RightButton)
    {
      QGraphicsScene::mouseDoubleClickEvent (mouseEvent);
      mouseEvent->ignore ();
    }
  }
}
