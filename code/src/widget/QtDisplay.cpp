#include "QtDisplay.hpp"

#include "config.hpp"

#include <cmath>
#include <string>
#include <vector>

//!< The size of the icon IN the QPushButton
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

namespace widget
{
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
    m_scene = new QGraphicsScene (m_window);
    m_tool_scene = new QGraphicsScene (m_window);
    m_view->setScene (m_scene);
    m_tool->setScene (m_tool_scene);
    m_shapes = new QVector<QGraphicsItem*>;
    m_scroll_area = new QScrollArea (m_window);

    QSize default_size (DEFAULT_WINDOW_LENGTH, DEFAULT_WINDOW_HEIGHT);
    QRectF fixed_size (-(DEFAULT_SCENE_LENGTH / 2), -(DEFAULT_SCENE_HEIGHT / 2),
                       DEFAULT_SCENE_LENGTH, DEFAULT_SCENE_HEIGHT);
    m_scene->setSceneRect (fixed_size);
    this->setFixedSize (default_size);
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

  void QtDisplay::draw_rectangle (const shape::Rectangle& rect)
  {
    shape::Point pos = rect.get_position ();
    QColor color = rect.get_color ();
    QGraphicsRectItem* rect_item = new QGraphicsRectItem (
     pos.x (), pos.y (), rect.get_width (), rect.get_height ());
    rect_item->setFlag (QGraphicsItem::ItemIsSelectable);
    rect_item->setFlag (QGraphicsItem::ItemIsMovable);
    rect_item->setFlag (QGraphicsItem::ItemSendsGeometryChanges);
    rect_item->setBrush (color);
    m_scene->addItem (rect_item);
    m_shapes->append (rect_item);
  }

  void QtDisplay::draw_polygon (const shape::Polygon& poly)
  {
    QVector<QPointF> points;
    int n = poly.get_nb_sides ();
    // Radius of the exterior circle
    // ref : https://www.mathopenref.com/polygonradius.html
    double rad = (poly.get_side_length () / (2 * (sin (180 / n * M_PI / 180))));

    // Searching all points coordinates
    for (int i = 0; i < n; ++i)
    {
      points.push_back (
       QPointF (rad * cos (2 * M_PI * i / n), rad * sin (2 * M_PI * i / n)));
    }

    // Adusting position
    shape::Point pos = poly.get_position ();
    for (int i = 0; i < n; ++i)
    {
      points[i].setX (points[i].rx () + pos.x ());
      points[i].setY (points[i].ry () + pos.y ());
    }

    QColor color = poly.get_color ();
    QPolygonF poly_tmp (points);
    QGraphicsPolygonItem* poly_item = new QGraphicsPolygonItem (poly_tmp);
    poly_item->setFlag (QGraphicsItem::ItemIsSelectable);
    poly_item->setFlag (QGraphicsItem::ItemIsMovable);
    poly_item->setFlag (QGraphicsItem::ItemSendsGeometryChanges);
    poly_item->setBrush (color);
    m_scene->addItem (poly_item);
    m_shapes->append (poly_item);
  }

  void QtDisplay::mousePressEvent (QMouseEvent* event)
  {
    if (event->button () == Qt::LeftButton &&
        m_window->geometry ().contains (event->pos ()))
    {
      std::cout << "Bonjour poto " << std::endl;
    }
  }
}
