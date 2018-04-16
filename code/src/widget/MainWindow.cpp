#include "MainWindow.hpp"

#include <QGridLayout>
#include <QIcon>
#include <QLabel>
#include <QPixmap>
#include <QToolBar>
#include <string>

#define ICON_SIZE 32
#define BUTTON_SIZE 40

namespace widget
{
  static void set_button_image (QPushButton* button, std::string img_name)
  {
    const char* c = img_name.c_str ();
    QPixmap map (c);
    QIcon icon (map);
    button->setIcon (icon);
    button->setIconSize (QSize (ICON_SIZE, ICON_SIZE));
    button->resize (ICON_SIZE, ICON_SIZE);
    button->setMinimumSize (BUTTON_SIZE, BUTTON_SIZE);
    button->setMaximumSize (BUTTON_SIZE, BUTTON_SIZE);
  }

  MainWindow::MainWindow () : QMainWindow ()
  {
    QWidget* window = new QWidget;
    window->setMinimumSize (800, 600);
    m_scene = new QGraphicsView;

    QPixmap tmp ("../ressources/bin.png");
    QPixmap trash = tmp.scaled (QSize (BUTTON_SIZE, BUTTON_SIZE));

    QToolBar* tools = addToolBar ("tools");

    QLabel* trash_label = new QLabel;
    trash_label->setPixmap (trash);

    // Save button
    m_save_button = new QPushButton;
    set_button_image (m_save_button, "../ressources/save.png");

    // Load button
    m_load_button = new QPushButton;
    set_button_image (m_load_button, "../ressources/load.png");

    // Undo button
    m_undo_button = new QPushButton;
    set_button_image (m_undo_button, "../ressources/undo.png");

    // Redo button
    m_redo_button = new QPushButton;
    set_button_image (m_redo_button, "../ressources/redo.png");

    QGridLayout* layout = new QGridLayout;
    layout->addWidget (m_save_button, 0, 0);
    layout->addWidget (m_load_button, 0, 1);
    layout->addWidget (m_undo_button, 0, 2);
    layout->addWidget (m_redo_button, 0, 3);
    layout->addWidget (m_scene, 1, 1, 5, 4);
    layout->addWidget (tools, 1, 0, 4, 0);
    layout->addWidget (trash_label, 5, 0);

    window->setLayout (layout);
    window->show ();
  }

  MainWindow::~MainWindow ()
  {
    delete m_save_button;
    delete m_load_button;
    delete m_undo_button;
    delete m_redo_button;
  }
}
