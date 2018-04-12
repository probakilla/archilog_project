#ifndef SHAPEINTERFACE_HPP
#define SHAPEINTERFACE_HPP

namespace shape
{
  class ShapeInterface
  {
  public:
    virtual void add_shape (const ShapeInterface& shape) = 0;

    virtual void remove_shape (const ShapeInterface& shape) = 0;
    
    virtual void draw () = 0;

    virtual void resize (double size_coeff) = 0;

    virtual bool operator== (const ShapeInterface& shape) = 0;
  };
}
#endif /* !defined(SHAPEINTERFACE_HPP) */
