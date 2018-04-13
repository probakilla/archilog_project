#ifndef ABSTRACTSHAPE_HPP
#define ABSTRACTSHAPE_HPP

#include "ShapeInterface.hpp"

#define DEFAULT_X 0
#define DEFAULT_Y 0

namespace shape
{
  using hex = int;

  //!< Structure of a 2D Point
  struct Point
  {
  public:
    Point (double x = DEFAULT_X, double y = DEFAULT_Y);
    Point (const Point& point);
    ~Point () = default;

    //!< Getter on abscissa
    double x () const;

    //!< Getter on ordinate
    double y () const;

    //!< Setter on abscissa
    void set_x (double x);

    //!< Setter on abscissa
    void set_y (double y);

    //!< Affectation operator
    Point& operator= (const Point& point);

    //!< Comparison operator
    bool operator== (const Point& point) const;

  private:
    double m_x; //!< abscissa
    double m_y; //!< ordinades
  };

  //!< Factorisation for shape classes
  class AbstractShape : public ShapeInterface
  {
  public:
    //!< Destructor, deletes points members
    virtual ~AbstractShape () = default;

    virtual void add_shape (const ShapeInterface& shape);

    virtual void remove_shape (const ShapeInterface& shape);

    virtual bool operator== (const ShapeInterface& shape) override;

    virtual AbstractShape& operator= (const AbstractShape& shape);

  protected:
    /*!
     * @brief Empty constructor of shape::AbstractShape
     *
     * Set the position to (0, 0) and the color to white.
     */
    AbstractShape ();

    /*!
     * @brief Constructor of shape::AbstractShape
     *
     * @param pos The default position of the shape.
     */
    AbstractShape (const Point& pos);

    //!< Getter on position
    Point get_position () const;

    //!< Getter on rotation center
    Point get_rotation_center () const;

    //!< Setter on position
    void set_position (const Point& point);

    //!< Setter on rotation center
    void set_rotation_center (const Point& point);

  private:
    Point m_position;        //!< Current position of the shape
    Point m_rotation_center; //!< Center of rotation of the shape
  };
}
#endif /* !defined(ABSTRACTSHAPE_HPP) */
