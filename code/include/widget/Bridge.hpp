#ifndef BRIDGE_HPP
#define BRIDGE_HPP

#include "Rectangle.hpp"
#include "Polygon.hpp"
#include "WindowFactoryInterface.hpp"
#include "WindowInterface.hpp"

namespace widget
{
  /*!
   * @brief User interface of the bridge
   *
   * This is the interface of the bridge design pattern. Its implementation is
   * WindowInterface. Defines the actions of the user.
   */
  class Bridge
  {
  public:
    /*!
     * @brief Constructor of widget::Bridge
     *
     * Initialize the implementation of the bridge using a factory.
     * @param factory A factory creating the wanted implementation.
     */
    Bridge (WindowFactoryInterface* factory);

    //!< Deleting Bridge::m_imp member
    ~Bridge ();

    //!< Displaying the implementation of the bridge.
    virtual void show ();

    //!< Drawing a rectangle in the Bridge::m_imp
    virtual void draw_rectangle (shape::Rectangle& rect);

    //!< Drawing a polygon in the Bridge::m_imp
    virtual void draw_polygon (shape::Polygon& poly);

  private:
    WindowInterface* m_imp;
  };
}
#endif /* !defined(BRIDGE_HPP) */
