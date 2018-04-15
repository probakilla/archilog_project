#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

namespace widget
{
  class MainWindow
  {
  public:
    MainWindow ();
    virtual ~MainWindow () = default;

    void run (int argc, char** argv);

  private:
  };
}
#endif /* !defined(MAINWINDOW_HPP) */
