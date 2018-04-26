#ifndef SHAPEINTERFACE_HPP
#define SHAPEINTERFACE_HPP

#include "ObserverInterface.hpp"

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>

namespace shape
{
  class ShapeInterface
  {
  public:
    virtual ~ShapeInterface () = default;

    virtual bool add_shape (const ShapeInterface& shape) = 0;

    virtual bool remove_shape (const ShapeInterface& shape) = 0;

    virtual bool operator== (const ShapeInterface& shape) = 0;

    virtual void attach (widget::ObserverInterface* obs) = 0;

    virtual void detach (widget::ObserverInterface* obs) = 0;

    virtual void notify () = 0;

  private:
    friend boost::serialization::access;
    template <class Archive> void serialize (Archive&, const unsigned int) {}
  };
}
//BOOST_SERIALIZATION_ASSUME_ABSTRACT(ShapeInterface)
BOOST_CLASS_EXPORT_KEY (shape::ShapeInterface);
#endif /* !defined(SHAPEINTERFACE_HPP) */
