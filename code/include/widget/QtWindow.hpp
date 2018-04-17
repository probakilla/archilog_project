#ifndef QTWINDOW_HPP
#define QTWINDOW_HPP

#include "QtDisplay.hpp"
#include "Rectangle.hpp"
#include "WindowInterface.hpp"

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

    //!< Deleting the QtWindow::m_window mezzmber
    ~QtWindow ();

    //!< Displaying the QtWindow::m_window member
    void show ();

    /*!
     * @brief Draw a shape::Rectangle in the window
     *
     * Call the method draw_rectangle of the widget::QtDisplay member
     * @param rect The shape::Rectangle to draw
     */
    void draw_rectangle (const shape::Rectangle& rect);

    /*!
     * @brief Draw a shape::Polygon in the window
     *
     * Call the method draw_polygon of the widget::QtDisplay member
     * @param poly The shape::Polygon to draw
     */
    void draw_polygon (const shape::Polygon& poly);

  private:
    //!< The widget::QtDisplay used for the application display
    QtDisplay* m_window;
  };
}
#endif // !defined(QTWINDOW_HPP)
