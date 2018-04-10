#include "main_window.hpp"

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>

namespace view
{
  main_window::main_window () {}

  void main_window::run (int argc, char** argv)
  {
    QApplication app (argc, argv);
    QMainWindow window;

    window.setMinimumSize (800, 800);
    window.show ();
    app.exec ();
  }
}
