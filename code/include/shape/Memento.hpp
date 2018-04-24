#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include "MementoInterface.hpp"

namespace shape
{
  /*!
   * @brief Class shape::Memento following the design pattern Memento.
   *
   * @tparam T Type to store the state.
   */
  template <typename T> class Memento : public MementoInterface
  {
  public:
    /*!
     * @brief Constructor of the shape::Memento
     *
     * @param state The object's state we want to store.
     */
    Memento (T state) : m_state (state) {}

    Memento () {}

    //!< Default destructor.
    ~Memento () = default;

    //!< Getter on Memento::m_state.
    T get_state () { return m_state; }

    //!< Setter on Memento::m_state.
    void set_state (T state) { m_state = state; }

  private:
    T m_state; //!< Stored state.
  };
}
#endif /* !defined(MEMENTO_HPP) */
