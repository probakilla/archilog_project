#ifndef QTWINDOWFACTORY_HPP
#define QTWINDOWFACTORY_HPP

#include "WindowFactoryInterface.hpp"
#include "WindowInterface.hpp"

namespace widget
{
  /*!
   * @brief Factory derived from widget::WindowFactoryInterface
   *
   * This is the concrete factory used to initialize the widgetQtMainWindow,
   * whitch is an implementation of WindowInterface.
   */
  class QtWindowFactory : public WindowFactoryInterface
  {
  public:
    //!< Empty constructor of QtWindowFactory
    QtWindowFactory ();

    //!< Default destructor
    ~QtWindowFactory () = default;

    /*!
     * @brief Overrided method from widget::WindowFactoryInterface
     *
     * Overrided method from widget::WindowFactoryInterface, returns an instance
     * of QtMainWindow.
     */
    WindowInterface* create_window ();
  };
}

#endif // !defined QTWINDOWFACTORY_HPP
