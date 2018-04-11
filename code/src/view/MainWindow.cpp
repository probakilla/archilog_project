#include "MainWindow.hpp"

#include <QApplication>
#include <QMainWindow>

namespace view
{
  MainWindow::MainWindow () {}

  void MainWindow::run (int argc, char** argv)
  {
    QApplication app (argc, argv);
    QMainWindow window;

    window.setMinimumSize (800, 800);
    window.show ();
    app.exec ();
  }
}
