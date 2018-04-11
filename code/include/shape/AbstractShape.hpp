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

    //!< Getter on position
    Point position () const;

    //!< Getter on rotation center
    Point rotation_center () const;

    //!< Getter on color
    int color () const;

    //!< Setter on position
    void set_position (const Point& point);

    //!< Setter on rotation center
    void set_rotation_center (const Point& point);

    //!< Setter on color
    void set_color (hex color);

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
     * @param color The color in hexadecimal of the shape.
     */
    AbstractShape (const Point& pos, hex color = DEFAULT_COLOR);

  private:
    Point m_position;        //!< Current position of the shape
    Point m_rotation_center; //!< Center of rotation of the shape
    hex m_color;             //!< Color in hexadecimal of the shape
  };
}
#endif /* !defined(ABSTRACTSHAPE_HPP) */
