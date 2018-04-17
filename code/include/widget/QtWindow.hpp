#ifndef QTWINDOW_HPP
#define QTWINDOW_HPP

#include "WindowInterface.hpp"
#include "QtDisplay.hpp"

namespace widget
{
  /*!
   * @brief Implementation of a Window using Qt library
   *
   * This is an implementation of WindowInterface following the Bridge
   * design pattern. This implementation uses the Qt library.
   */
  class QtWindow : public WindowInterface
  {
  public:
    //!< Creatin a new QtDisplay
    QtWindow ();

    //!< Deleting the QtWindow::m_window member
    ~QtWindow ();

    //!< Displaying the QtWindow::m_window member
    void show ();

  private:
    //!< The widget::QtDisplay used for the application display
    QtDisplay* m_window;
  };
}
#endif // !defined(QTWINDOW_HPP)
