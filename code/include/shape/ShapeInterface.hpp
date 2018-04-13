#ifndef SHAPEINTERFACE_HPP
#define SHAPEINTERFACE_HPP

namespace shape
{
  class ShapeInterface
  {
  public:
    virtual ~ShapeInterface () = default;

    virtual bool add_shape (const ShapeInterface& shape) = 0;

    virtual bool remove_shape (const ShapeInterface& shape) = 0;

    virtual bool operator== (const ShapeInterface& shape) = 0;
  };
}
#endif /* !defined(SHAPEINTERFACE_HPP) */
