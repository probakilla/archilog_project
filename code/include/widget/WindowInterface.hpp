#ifndef WINDOWINTERFACE_HPP
#define WINDOWINTERFACE_HPP

#include "Rectangle.hpp"
#include "Polygon.hpp"

namespace widget
{
  /*!
   * @brief The interface for the implementation part of the bridge
   *
   * The methods presents here will be mostly called by the user interface
   * widget::Window.
   */
  class WindowInterface
  {
  public:
    //!< Default destructor
    virtual ~WindowInterface () = default;

    //!< Display the program
    virtual void show () = 0;

    //!< Draw a rectangle
    virtual void draw_rectangle (const shape::Rectangle& rect) = 0;

    //!< Draw a polygon
    virtual void draw_polygon (const shape::Polygon& poly) = 0;
  };
}

#endif // !defined WINDOWINTERFACE_HPP
