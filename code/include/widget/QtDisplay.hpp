#ifndef QTDISPLAY_HPP
#define QTDISPLAY_HPP

#include "CommandInterface.hpp"
#include "Polygon.hpp"
#include "QtMainScene.hpp"
#include "QtPolygon.hpp"
#include "Rectangle.hpp"
#include "QtRectangle.hpp"

#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QScrollArea>
#include <QMainWindow>
#include <QGraphicsView>
#include <vector>

namespace widget
{
  /*!
   * @brief Class used for the display using Qt library
   *
   * Class derived from QMainWindow where all the display will be
   */
  class QtDisplay : public QMainWindow
  {
    Q_OBJECT
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

    /*!
     * @brief Draw a shape::Rectangle
     *
     * @param rect The shape::Rectangle we want to draw
     */
    void draw_rectangle (shape::Rectangle& rect);

    /*!
     * @brief Draw a shape::Rectangle
     *
     * @param rect The shape::Rectangle we want to draw
     */
    void draw_polygon (shape::Polygon& poly);

    //!< Currently selected item  !! saucisse saucisse !!.
    static QtRectangle* cur_rect;
    static QtPolygon* cur_poly;

  private slots:
    void save ();
    void load ();
    void undo ();
    void redo ();

    //!< Show a QColorDialog to chose a color for the rectangle
    void edit_rectangle_color ();
    //!< Show a QInputDialog to chose a width for the rectangle
    void edit_rectangle_width ();
    //!< Show a QInputDialog to chose a height for the rectangle
    void edit_rectangle_height ();
    //!< Show a QInputDialog to chose a angle for the rotation
    void rectangle_rotation ();

    //!< Show a QColorDialog to chose a color for the polygon
    void edit_polygon_color ();
    //!< Show a QInputDialog to chose the number of sides of the polygon
    void edit_polygon_nb_sides ();

  private:
    /*!
     * @brief Show the dialog for shape editing.
     *
     * Show a dialog for the selection of a double value
     * @param name The name of the dialog
     * @param def_val The default value of the dialog
     * @param min_val The maximum value possible for the dialog
     * @param max_val The maximum value possible for the dialog
     * @return The selected value if correct, -1.0 if there is an error
     */
    double input_dialog (const QString& name, double def_val, double min_val,
                         double max_val) const;

    //!< Create actions for the QtRectangle's context menu
    void connect_rectangle (QtRectangle* rect);
    //!< Create actions for the QtPolygon's context menu
    void connect_polygon (QtPolygon* poly);
    //!< The window where the layout is
    QWidget* m_window;
    //!< The layout where all widgets are
    QGridLayout* m_layout;
    //!< The label of the trash at the bottom of the toolbar
    QLabel* m_bin_label;
    //!< Where the bin icon is
    QScrollArea* m_scroll_area;
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
    QtMainScene* m_scene;
    //!< Where the thumbnails shows
    QGraphicsScene* m_tool_scene;
    //!< The toolbar where the thumbnails of the shape will be stored
    QGraphicsView* m_tool;
    //!< Vector containing all shapes
    std::vector<shape::ShapeInterface*>* m_shapes;
    //!< Vector containing all commands that can be undo
    std::vector<command::CommandInterface*>* m_undoable_commands;
    //!< Vector containing all commands that can be redo
    std::vector<command::CommandInterface*>* m_redoable_commands;
  };
}
#endif /* !defined(QTDISPLAY_HPP) */
