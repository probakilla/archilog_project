#include "QtDisplay.hpp"

#include "PolyColorCommand.hpp"
#include "PolyNbSidesCommand.hpp"
#include "PolyRotateCommand.hpp"
#include "PolySideLengthCommand.hpp"
#include "QtPolygon.hpp"
#include "QtRectangle.hpp"
#include "RectColorCommand.hpp"
#include "RectHeightCommand.hpp"
#include "RectRotateCommand.hpp"
#include "RectWidthCommand.hpp"
#include "config.hpp"

#include <QColorDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <boost/serialization/vector.hpp>
#include <cmath>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

//!< The size of the icon in the QPushButton
#define ICON_SIZE 32
//!< The size of the QPushButton, should be greater than ICON_SIZE
#define BUTTON_SIZE 40
//!< Path to the ressources directory.
#define RESSOURCES_PATH std::string (RESSOURCES_LOCATION)

#define DEFAULT_WINDOW_LENGTH 1024
#define DEFAULT_WINDOW_HEIGHT 712
//!< The scene must be smaller than the window
#define DEFAULT_SCENE_LENGTH 800
#define DEFAULT_SCENE_HEIGHT 600

#define _USE_MATH_DEFINES

#define DECIMALS 2
#define MAX_DIALOG 1024.0
#define MAX_ANGLE 360.0
#define MIN_LENGTH 1.0
#define MIN_DIALOG 0.0
#define MIN_NB_SIDES 3.0
#define STEP 1

namespace widget
{
  QtRectangle* QtDisplay::cur_rect;
  QtPolygon* QtDisplay::cur_poly;

  /*!
   * @brief Set the image of a QPushButton
   *
   * @param button A pointer to the button to QPushButton
   * @param img_name The path to the image
   */
  static void set_button_image (QPushButton* button, std::string img_name)
  {
    // convertion str to const char*
    const char* c = img_name.c_str ();

    // Setting the image
    QPixmap map (c);
    QIcon icon (map);
    button->setIcon (icon);
    button->setIconSize (QSize (ICON_SIZE, ICON_SIZE));
    button->resize (ICON_SIZE, ICON_SIZE);
    button->setMinimumSize (BUTTON_SIZE, BUTTON_SIZE);
    button->setMaximumSize (BUTTON_SIZE, BUTTON_SIZE);
  }

  QtDisplay::QtDisplay () : QMainWindow ()
  {
    // Initializations
    m_window = new QWidget;
    m_layout = new QGridLayout (m_window);
    m_bin_label = new QLabel (m_window);
    m_save_button = new QPushButton (m_window);
    m_load_button = new QPushButton (m_window);
    m_undo_button = new QPushButton (m_window);
    m_redo_button = new QPushButton (m_window);
    m_tool = new QGraphicsView (m_window);
    m_view = new QGraphicsView (m_window);
    m_view->setDragMode (QGraphicsView::RubberBandDrag);
    m_commands = shape::AllCommands::get_instance ();

    m_scene = new QGraphicsScene (m_window);
    m_tool_scene = new QGraphicsScene (m_window);
    m_view->setScene (m_scene);
    m_tool->setScene (m_tool_scene);
    m_shapes = new std::vector<shape::ShapeInterface*>;
    m_scroll_area = new QScrollArea (m_window);

    QSize default_size (DEFAULT_WINDOW_LENGTH, DEFAULT_WINDOW_HEIGHT);
    this->setMinimumSize (default_size);
    this->setCentralWidget (m_window);

    // Setting the image in the QtDisplay::m_bin_label
    char trash_path[strlen (RESSOURCES_LOCATION) + strlen ("bin.png")];
    strcpy (trash_path, RESSOURCES_LOCATION);
    strcat (trash_path, "bin.png");
    QPixmap tmp (trash_path);
    QPixmap trash = tmp.scaled (QSize (ICON_SIZE, ICON_SIZE));
    m_bin_label->setPixmap (trash);
    m_scroll_area->setWidget (m_bin_label);
    m_scroll_area->setFixedSize (BUTTON_SIZE, BUTTON_SIZE);

    // Setting buttons images
    set_button_image (m_save_button, RESSOURCES_PATH + "save.png");
    set_button_image (m_load_button, RESSOURCES_PATH + "load.png");
    set_button_image (m_undo_button, RESSOURCES_PATH + "undo.png");
    set_button_image (m_redo_button, RESSOURCES_PATH + "redo.png");

    // Connection buttons to slot
    connect (m_save_button, SIGNAL (released ()), this, SLOT (save ()));
    connect (m_load_button, SIGNAL (released ()), this, SLOT (load ()));
    connect (m_undo_button, SIGNAL (released ()), this, SLOT (undo ()));
    connect (m_redo_button, SIGNAL (released ()), this, SLOT (redo ()));

    // Adding widgets in layout.
    m_layout->addWidget (m_save_button, 0, 0);
    m_layout->addWidget (m_load_button, 0, 1);
    m_layout->addWidget (m_undo_button, 0, 2);
    m_layout->addWidget (m_redo_button, 0, 3);
    m_layout->addWidget (m_view, 1, 1, 5, 4);
    m_layout->addWidget (m_tool, 1, 0, 4, 0);
    m_layout->addWidget (m_scroll_area, 5, 0);
    // Adding layout in the window
    m_window->setLayout (m_layout);
  }

  QtDisplay::~QtDisplay ()
  {
    delete m_layout;
    delete m_tool;
    delete m_bin_label;
    delete m_save_button;
    delete m_load_button;
    delete m_undo_button;
    delete m_redo_button;
    delete m_scene;
    delete m_view;
    delete m_shapes;
    // Must be deleted in last
    delete m_window;
  }

  void QtDisplay::draw_rectangle (shape::Rectangle& rect)
  {
    QColor color = rect.get_color ();
    QtRectangle* rect_item = new QtRectangle (&rect, this);
    rect.attach (rect_item);
    rect_item->setBrush (color);
    m_scene->addItem (rect_item);
    shape::Point r_center = rect.get_rotation_center ();
    rect_item->setTransformOriginPoint (r_center.x (), r_center.y ());
    rect_item->setRotation (rect.get_rotation ());
    connect_rectangle (rect_item);
    m_shapes->push_back (&rect);
  }

  void QtDisplay::draw_polygon (shape::Polygon& poly)
  {
    QColor color = poly.get_color ();
    QtPolygon* poly_item = new QtPolygon (&poly, m_view);
    poly.attach (poly_item);
    poly_item->setFlag (QGraphicsItem::ItemIsSelectable);
    poly_item->setFlag (QGraphicsItem::ItemIsMovable);
    poly_item->setFlag (QGraphicsItem::ItemSendsGeometryChanges);
    poly_item->setBrush (color);
    m_scene->addItem (poly_item);
    shape::Point r_center = poly.get_rotation_center ();
    poly_item->setTransformOriginPoint (r_center.x (), r_center.y ());
    poly_item->setRotation (poly.get_rotation ());
    connect_polygon (poly_item);
    m_shapes->push_back (&poly);
  }

  static void invalid_save_file ()
  {
    QMessageBox msgBox;
    msgBox.setWindowTitle ("Warning !");
    msgBox.setText ("Unable to save the file.");
    msgBox.exec ();
  }

  void QtDisplay::save ()
  {
    QString filename = QFileDialog::getSaveFileName (
     this, tr ("Save Shapes"), "save.txt", tr (" (*.txt);;All Files (*)"));
    // The user cancel it.
    if (filename.size () == 0)
      return;
    std::ofstream save_file (filename.toStdString ());
    try
    {
      boost::archive::text_oarchive save_archive (save_file);
      save_archive << *m_shapes;
    }
    catch (const std::exception& ex)
    {
      invalid_save_file ();
      return;
    }
  }

  static void invalid_load_file ()
  {
    QMessageBox msgBox;
    msgBox.setWindowTitle ("Warning !");
    msgBox.setText ("Invalid load file.");
    msgBox.exec ();
  }

  void QtDisplay::load ()
  {
    QString filename = QFileDialog::getOpenFileName (
     this, tr ("Load Shapes"), ".txt", tr (" (*.txt);;All Files (*)"));
    // The user cancel it.
    if (filename.size () == 0)
      return;
    std::ifstream load_file (filename.toStdString ());
    std::vector<shape::ShapeInterface*> load_shapes;
    try
    {
      boost::archive::text_iarchive save_archive (load_file);
      save_archive >> load_shapes;
    }
    catch (const std::exception& ex)
    {
      invalid_load_file ();
      return;
    }
    // Clear existing shapes.
    m_shapes->clear ();
    m_commands->clear ();
    m_scene->clear ();
    m_view->viewport ()->update ();
    // Load and draw new shapes
    for (unsigned int i = 0; i < load_shapes.size (); ++i)
      if (typeid (*load_shapes[i]) == typeid (shape::Rectangle))
        draw_rectangle (static_cast<shape::Rectangle&> (*load_shapes[i]));
      else if (typeid (*load_shapes[i]) == typeid (shape::Polygon))
        draw_polygon (static_cast<shape::Polygon&> (*load_shapes[i]));
  }

  void QtDisplay::undo () { m_commands->undo (); }

  void QtDisplay::redo () { m_commands->redo (); }

  // CONNECTING SHAPES

  void QtDisplay::connect_rectangle (QtRectangle* rect)
  {
    QAction* color_act = new QAction (tr ("&Edit color"), m_view);
    connect (color_act, SIGNAL (triggered ()), this,
             SLOT (edit_rectangle_color ()));
    rect->get_menu ()->addAction (color_act);

    QAction* width_act = new QAction (tr ("&Edit width"), m_view);
    connect (width_act, SIGNAL (triggered ()), this,
             SLOT (edit_rectangle_width ()));
    rect->get_menu ()->addAction (width_act);

    QAction* height_act = new QAction (tr ("&Edit height"), m_view);
    connect (height_act, SIGNAL (triggered ()), this,
             SLOT (edit_rectangle_height ()));
    rect->get_menu ()->addAction (height_act);

    QAction* rotate_act = new QAction (tr ("&Rotate"), m_view);
    connect (rotate_act, SIGNAL (triggered ()), this,
             SLOT (rectangle_rotation ()));
    rect->get_menu ()->addAction (rotate_act);
  }

  void QtDisplay::connect_polygon (QtPolygon* poly)
  {
    QAction* color_act = new QAction (tr ("&Edit color"), m_view);
    connect (color_act, SIGNAL (triggered ()), this,
             SLOT (edit_polygon_color ()));
    poly->get_menu ()->addAction (color_act);

    QAction* nb_sides_act = new QAction (tr ("&Edit nb sides"), m_view);
    connect (nb_sides_act, SIGNAL (triggered ()), this,
             SLOT (edit_polygon_nb_sides ()));
    poly->get_menu ()->addAction (nb_sides_act);

    QAction* side_length_act = new QAction (tr ("&Edit side length"), m_view);
    connect (side_length_act, SIGNAL (triggered ()), this,
             SLOT (edit_polygon_side_length ()));
    poly->get_menu ()->addAction (side_length_act);

    QAction* rotate_act = new QAction (tr ("&Rotate"), m_view);
    connect (rotate_act, SIGNAL (triggered ()), this,
             SLOT (polygon_rotation ()));
    poly->get_menu ()->addAction (rotate_act);
  }

  // PRIVATE SLOTS

  void QtDisplay::edit_rectangle_color ()
  {
    QColor color = QColorDialog::getColor ();
    if (color.isValid ())
    {
      bool ok;
      int new_color = color.name ().replace ("#", "").toInt (&ok, 16);
      if (ok)
      {
        shape::Rectangle* tmp = cur_rect->get_rect ();
        command::RectColorCommand* cmd =
         new command::RectColorCommand (tmp, new_color);
        m_commands->add_undoable (cmd);
      }
    }
  }

  void QtDisplay::edit_rectangle_width ()
  {
    shape::Rectangle* tmp = cur_rect->get_rect ();
    double new_width =
     input_dialog ("Width : ", tmp->get_width (), MIN_LENGTH, MAX_DIALOG);
    if (new_width > 0)
    {
      command::RectWidthCommand* cmd =
       new command::RectWidthCommand (tmp, new_width);
      m_commands->add_undoable (cmd);
    }
  }

  void QtDisplay::edit_rectangle_height ()
  {
    shape::Rectangle* tmp = cur_rect->get_rect ();
    double new_height =
     input_dialog ("Height : ", tmp->get_height (), MIN_LENGTH, MAX_DIALOG);
    if (new_height > 0)
    {
      command::RectHeightCommand* cmd =
       new command::RectHeightCommand (tmp, new_height);
      m_commands->add_undoable (cmd);
    }
  }

  void QtDisplay::rectangle_rotation ()
  {
    shape::Rectangle* tmp = cur_rect->get_rect ();
    double new_angle =
     input_dialog ("Rotation angle : ", 0.0, MIN_DIALOG, MAX_ANGLE);
    if (new_angle > 0)
    {
      command::RectRotateCommand* cmd =
       new command::RectRotateCommand (tmp, new_angle);
      m_commands->add_undoable (cmd);
    }
  }

  void QtDisplay::edit_polygon_color ()
  {
    QColor color = QColorDialog::getColor ();
    if (color.isValid ())
    {
      bool ok;
      int new_color = color.name ().replace ("#", "").toInt (&ok, 16);
      if (ok)
      {
        shape::Polygon* tmp = cur_poly->get_poly ();
        command::PolyColorCommand* cmd =
         new command::PolyColorCommand (tmp, new_color);
        m_commands->add_undoable (cmd);
      }
    }
  }

  void QtDisplay::edit_polygon_nb_sides ()
  {
    shape::Polygon* tmp = cur_poly->get_poly ();
    bool ok;
    int new_nb = QInputDialog::getInt (
     m_view, tr ("QInputDialog::getInt()"), tr ("Number of sides : "),
     tmp->get_nb_sides (), MIN_NB_SIDES, MAX_DIALOG, STEP, &ok);
    if (ok)
    {
      command::PolyNbSidesCommand* cmd =
       new command::PolyNbSidesCommand (tmp, new_nb);
      m_commands->add_undoable (cmd);
    }
  }

  void QtDisplay::edit_polygon_side_length ()
  {
    shape::Polygon* tmp = cur_poly->get_poly ();
    double new_length = input_dialog (
     "Side lentgth : ", tmp->get_side_length (), MIN_LENGTH, MAX_DIALOG);
    if (new_length > 0)
    {
      command::PolySideLengthCommand* cmd =
       new command::PolySideLengthCommand (tmp, new_length);
      m_commands->add_undoable (cmd);
    }
  }

  void QtDisplay::polygon_rotation ()
  {
    shape::Polygon* tmp = cur_poly->get_poly ();
    double new_angle = input_dialog ("Rotation angle : ", tmp->get_rotation (),
                                     MIN_DIALOG, MAX_ANGLE);
    if (new_angle > 0)
    {
      command::PolyRotateCommand* cmd =
       new command::PolyRotateCommand (tmp, new_angle);
      m_commands->add_undoable (cmd);
    }
  }

  // PRIVATE METHODS

  double QtDisplay::input_dialog (const QString& name, double def_val,
                                  double min_val, double max_val) const
  {
    bool ok; // Check if the user accept
    double value =
     QInputDialog::getDouble (m_view, tr ("QInputDialog::getDouble()"), name,
                              def_val, min_val, max_val, DECIMALS, &ok);
    if (ok)
      return value;
    return -1.0;
  }
}
