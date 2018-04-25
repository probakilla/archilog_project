#include "QtRectangle.hpp"

#include "AbstractShape.hpp"

#include <QAction>
#include <QColorDialog>
#include <QInputDialog>
#include <QMenu>

#define DECIMALS 2

#define MIN_VALUE 1.0
#define MAX_ROTATION 360.0

namespace widget
{
  QtRectangle::QtRectangle (shape::Rectangle rect) :
   QGraphicsRectItem (rect.get_position ().x (), rect.get_position ().y (),
                      rect.get_width (), rect.get_height ()),
   m_menu (), m_rect (rect)
  {
    this->setTransformOriginPoint (QPoint (m_rect.get_rotation_center ().x (),
                                           m_rect.get_rotation_center ().y ()));
    // Adjust the position.
    setPos (x () - rect.get_width () / 2, y () - rect.get_height () / 2);
  }

  QtRectangle::~QtRectangle () {}

  QMenu* QtRectangle::get_menu () const { return m_menu; }

  void QtRectangle::contextMenuEvent (QGraphicsSceneContextMenuEvent* event)
  {
    if (event->reason () == QGraphicsSceneContextMenuEvent::Mouse)
    {
      m_menu->exec (event->screenPos ());
    }
  }

  void QtRectangle::edit_color ()
  {
    QColor color = QColorDialog::getColor ();
    if (color.isValid ())
    {
      m_rect.set_color (color.value ());
      setBrush (color);
      this->update ();
    }
  }

  void QtRectangle::edit_height ()
  {
    double new_height = input_dialog ("Height : ", m_rect.get_height ());
    if (new_height > 0) // new_height = -1.0 if there was a error
    {
      m_rect.set_height (new_height);
      QRectF tmp = this->rect ();
      tmp.setHeight (new_height);
      this->setRect (tmp);
      this->update ();
    }
  }

  void QtRectangle::edit_width ()
  {
    double new_width = input_dialog ("Width : ", m_rect.get_width ());
    if (new_width > 0)
    {
      m_rect.set_width (new_width);
      QRectF tmp = this->rect ();
      tmp.setWidth (new_width);
      this->setRect (tmp);
      this->update ();
    }
  }

  void QtRectangle::edit_rotation_center ()
  {
    double new_x =
     input_dialog ("Abscissa : ", m_rect.get_rotation_center ().x ());
    double new_y =
     input_dialog ("Ordinate : ", m_rect.get_rotation_center ().y ());
    if (new_x > 0 && new_y > 0)
    {
      shape::Point p (new_x, new_y);
      m_rect.set_rotation_center (p);
      this->setTransformOriginPoint (new_x, new_y);
    }
  }

  void QtRectangle::rotate ()
  {
    double rotation = input_dialog ("Rotation : ", 0.0, MAX_ROTATION);
    if (rotation > 0)
    {
      this->setRotation (rotation);
      this->update ();
    }
  }

  void QtRectangle::edit_rounding ()
  {
    double new_rounding =
     input_dialog ("Rounding coefficient : ", m_rect.get_rounding_coeff ());
    if (new_rounding > 0)
    {
      m_rect.set_rounding_coeff (new_rounding);
    }
  }
}
