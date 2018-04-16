#include "MainWindow.hpp"

#include <QApplication>

int main (int argc, char** argv)
{
  QApplication app (argc, argv);
  widget::MainWindow w;

  return app.exec ();
}
