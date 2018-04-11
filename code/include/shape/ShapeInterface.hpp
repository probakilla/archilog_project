#ifndef SHAPEINTERFACE_HPP
#define SHAPEINTERFACE_HPP

namespace shape
{
  class ShapeInterface
  {
  public:
    virtual void draw () = 0;

    virtual void resize (const double size_coeff) = 0;
  };
}
#endif /* !defined(SHAPEINTERFACE_HPP) */
