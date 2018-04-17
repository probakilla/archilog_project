#include "Bridge.hpp"

namespace widget
{
  Bridge::Bridge (WindowFactoryInterface* factory)
  {
    m_imp = factory->create_window ();
  }

  Bridge::~Bridge ()
  {
    delete m_imp;
  }

  void Bridge::show ()
  {
    m_imp->show ();
  }
}
