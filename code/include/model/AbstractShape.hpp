#ifndef ABSTRACTSHAPE_HPP
#define ABSTRACTSHAPE_HPP

#include "ShapeInterface.hpp"

#define DEFAULT_X 0
#define DEFAULT_Y 0
#define DEFAULT_COLOR 0xffffff

namespace model
{
  using hex = int;

  //!< Structure of a 2D Point
  struct Point
  {
    Point (int x = DEFAULT_X, int y = DEFAULT_Y);
    ~Point () = default;

    int m_x; /*!< abscissa */
    int m_y; /*!< ordinades */
  };

  //!< Factorisation for shape classes
  class AbstractShape : public ShapeInterface
  {
  public:
    //!< Default destructor
    virtual ~AbstractShape () = default;

  protected:
    /*!
     * @brief Constructor of model::AbstractShape
     *
     * @param pos The default position of the shape.
     */
    AbstractShape (Point pos);

    Point m_position;            //!< Current position of the shape
    Point m_rotation_center;     //!< Center of rotation of the shape
    hex m_color = DEFAULT_COLOR; //!< Color in hexadecimal of the shape
  };
}
#endif /* !defined(ABSTRACTSHAPE_HPP) */
