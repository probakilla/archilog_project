#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsView>

namespace widget
{
  class MainWindow : public QMainWindow
  {
  public:
    MainWindow ();
    ~MainWindow ();

  private:
    QPushButton* m_save_button;
    QPushButton* m_load_button;
    QPushButton* m_undo_button;
    QPushButton* m_redo_button;
    QGraphicsView* m_scene;
  };
}
#endif /* !defined(MAINWINDOW_HPP) */
