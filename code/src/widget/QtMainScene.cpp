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
  }
}
