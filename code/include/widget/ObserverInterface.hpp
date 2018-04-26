#ifndef OBSERVERINTERFACE_HPP
#define OBSERVERINTERFACE_HPP

namespace widget
{
  class ObserverInterface
  {
  public:
    virtual ~ObserverInterface () = default;

    virtual void update_shape () = 0;
  };
}
#endif /* !defined(OBSERVERINTERFACE_HPP) */
