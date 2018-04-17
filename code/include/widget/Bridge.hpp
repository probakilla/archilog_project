#ifndef BRIDGE_HPP
#define BRIDGE_HPP

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

  private:
    WindowInterface* m_imp;
  };
}
#endif /* !defined(BRIDGE_HPP) */
