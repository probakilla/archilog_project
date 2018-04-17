#ifndef QTMAINWINDOW_HPP
#define QTMAINWINDOW_HPP

#include "WindowInterface.hpp"
#include "QtWindow.hpp"

namespace widget
{
  /*!
   * @brief Implementation of a Window using Qt library
   *
   * This is an implementation of WindowInterface following the Bridge
   * design pattern. This implementation uses the Qt library.
   */
  class QtMainWindow : public WindowInterface
  {
  public:
    //!< Creatin a new QtWindow
    QtMainWindow ();

    //!< Deleting the QtMainWindow::m_window member
    ~QtMainWindow ();

    //!< Displaying the QtMainWindow::m_window member
    void show ();

  private:
    //!< The widget::QtWindow used for the application display
    QtWindow* m_window;
  };
}
#endif // !defined(QTMAINWINDOW_HPP)
