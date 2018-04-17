#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "WindowInterface.hpp"
#include "WindowFactoryInterface.hpp"

namespace widget
{
  /*!
   * @brief User interface of the bridge
   *
   * This is the interface of the bridge design pattern. Its implementation is
   * WindowInterface. Defines the actions of the user.
   */
  class Window
  {
  public:
    /*!
     * @brief Constructor of widget::Window
     *
     * Initialize the implementation of the bridge using a factory.
     * @param factory A factory creating the wanted implementation.
     */
    Window (WindowFactoryInterface* factory);

    //!< Deleting Window::m_imp member
    ~Window ();

    //!< Displaying the implementation of the bridge.
    virtual void show ();

  private:
    WindowInterface* m_imp;
  };
}
#endif /* !defined(WINDOW_HPP) */
