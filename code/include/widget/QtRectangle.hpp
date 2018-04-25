#ifndef QTRECTANGLE_HPP
#define QTRECTANGLE_HPP

#include "Rectangle.hpp"

#include <QAction>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QString>

#define MAX_VALUE 1024.0

namespace widget
{
  class QtRectangle : public QObject, public QGraphicsRectItem
  {
    Q_OBJECT
  public:
    QtRectangle (shape::Rectangle rect, QWidget* parent = 0);
    ~QtRectangle ();

    //!< The context menu of the shape, open with right click
    void contextMenuEvent (QGraphicsSceneContextMenuEvent* event);

  private slots:
    //!< Show a QColorDialog to chose a color
    void edit_color ();
    //!< Show a QInputDialog to edit the height of the widget::QtRectangle
    void edit_height ();
    //!< Show a QInputDialog to edit the width of the widget::QtRectangle
    void edit_width ();
    //!< Show two QInputDialogs to edit the coordinates of the rotation center
    void edit_rotation_center ();
    //!< Show a QInputDialog to edit the rotation center
    void rotate ();
    //!< Show a QInputDialog to edit the rounding coefficient of the widget::QtRectangle
    void edit_rounding ();

  private:
    QWidget* m_parent;       //!< The parent of the QtRectangle
    shape::Rectangle m_rect; //!< The shape::Rectangle corresponding

    /*!
     * @brief Show the dialog for shape editing.
     *
     * Show a dialog for the selection of a double value
     * @param name The name of the dialog
     * @param def_val The default value of the dialog
     * @param max_val The maximumu value possible for the dialog
     * @return The selected value if correct, -1.0 if there is an error
     */
    double input_dialog (const QString& name, double def_val,
                         double max_val = MAX_VALUE) const;
  };
}

#endif // !defined QTRECTANGLE_HPP
