#ifndef QTDISPLAY_HPP
#define QTDISPLAY_HPP

#include "Polygon.hpp"
#include "Rectangle.hpp"

#include <QtGui>

namespace widget
{
  /*!
   * @brief Class used for the display using Qt library
   *
   * Class derived from QMainWindow where all the display will be
   */
  class QtDisplay : public QMainWindow
  {
  public:
    /*!
     * @brief Initialize all members
     *
     * Initialize all member and set images of buttons, and putting them
     * in a layout for display purposes.
     */
    QtDisplay ();

    //!< Deleting all members
    ~QtDisplay ();

    //!< Displaying m_window
    void show ();

    /*!
     * @brief Draw a shape::Rectangle
     *
     * @param rect The shape::Rectangle we want to draw
     */
    void draw_rectangle (const shape::Rectangle& rect);

    /*!
     * @brief Draw a shape::Rectangle
     *
     * @param rect The shape::Rectangle we want to draw
     */
    void draw_polygon (const shape::Polygon& poly);

  private:
    //!< The window where the layout is
    QWidget* m_window;
    //!< The layout where all widgets are
    QGridLayout* m_layout;
    //!< The label of the trash at the bottom of the toolbar
    QLabel* m_bin_label;
    //!< The save button
    QPushButton* m_save_button;
    //!< The load button
    QPushButton* m_load_button;
    //!< The undo button
    QPushButton* m_undo_button;
    //!< The redo button
    QPushButton* m_redo_button;
    //!< The white panel where shape will appear
    QGraphicsView* m_view;
    //!< Where we draw shapes
    QGraphicsScene* m_scene;
    //!< The toolbar where the thumbnails of the shape will be stored
    QToolBar* m_tool;
    //!< QVector containing all shapes
    QVector<QGraphicsItem*>* m_shapes;
  };
}
#endif /* !defined(QTDISPLAY_HPP) */
