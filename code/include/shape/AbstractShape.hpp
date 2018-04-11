#ifndef ABSTRACTSHAPE_HPP
#define ABSTRACTSHAPE_HPP

#include "ShapeInterface.hpp"

#define DEFAULT_X 0
#define DEFAULT_Y 0
#define DEFAULT_COLOR 0xffffff

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
    double get_x () const;

    //!< Getter on ordinate
    double get_y () const;

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
    virtual ~AbstractShape ();

    virtual AbstractShape& operator= (const AbstractShape& shape) = 0;

  protected:
    /*!
     * @brief Constructor of shape::AbstractShape
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
