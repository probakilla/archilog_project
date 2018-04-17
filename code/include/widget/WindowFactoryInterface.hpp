#ifndef WINDOWFACTORYINTERFACE_HPP
#define WINDOWFACTORYINTERFACE_HPP

#include "WindowInterface.hpp"

namespace widget
{
  /*!
   * @brief The interface of factory.
   *
   * This factory is used to create the wanted implementation for the bridge if
   * function of the wanted API
   */
  class WindowFactoryInterface
  {
  public:
    //!< Default destructor
    virtual ~WindowFactoryInterface () = default;

    //!< Getting the wanted implementation in function of the sub-type
    virtual WindowInterface* create_window () = 0;
  };
}

#endif // !defined WINDOWFACTORYINTERFACE_HPP
