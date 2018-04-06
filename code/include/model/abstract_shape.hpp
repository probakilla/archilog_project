#ifndef ABSTRACT_SHAPE_HPP
#define ABSTRACT_SHAPE_HPP

#include "shape_interface.hpp"

#define DEFAULT_X 0
#define DEFAULT_Y 0
#define DEFAULT_COLOR 0xffffff

namespace model
{
  using hex = int;

  //!< Structure of a 2D point
  struct point
  {
    point (int x = DEFAULT_X, int y = DEFAULT_Y);
    ~point () = default;

    int m_x; /*!< abscissa */
    int m_y; /*!< ordinades */
  };

  //!< Factorisation for shape classes
  class abstract_shape : public shape_interface
  {
  public:
    //!< Default destructor
    virtual ~abstract_shape () = default;

  protected:
    /*!
     * @brief Constructor of model::abstract_shape
     *
     * @param pos The default position of the shape.
     */
    abstract_shape (point pos);

    point m_position;            //!< Current position of the shape
    point m_rotation_center;     //!< Center of rotation of the shape
    hex m_color = DEFAULT_COLOR; //!< Color in hexadecimal of the shape
  };
}
#endif /* !defined(ABSTRACT_SHAPE_HPP) */
