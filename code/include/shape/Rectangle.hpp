#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "AbstractPolygon.hpp"

//!< Default height value for the rectangle
#define DEFAULT_HEIGHT 8.0
//!< Default width value for the rectangle
#define DEFAULT_WIDTH 8.0
//!< Default rounding coeff for the rectangle
#define DEFAULT_ROUNDING 0.0

namespace shape
{
  class Rectangle : public AbstractPolygon
  {
  public:
    //!< Default destructor.
    ~Rectangle () = default;

    //!< Copy operator.
    Rectangle& operator= (const Rectangle& rec);

    //!< Comparison operator.
    bool operator== (const ShapeInterface& shape) override;

    //!< Getter on height.
    double get_height () const;

    //!< Getter on width.
    double get_width () const;

    //!< Getter on rounding coeff.
    double get_rounding_coeff () const;

  protected:
    /*!
     * @brief Constructor of the shape::Rectangle
     *
     * @param height (optional) The height of the shape::Rectangle
     * @param width (optional) The width of the shape::Rectangle
     * @param rounding (optional) The rounding coefficent of the
     * shape::Rectangle
     */
    Rectangle (double height = DEFAULT_HEIGHT, double width = DEFAULT_WIDTH,
               double rounding = DEFAULT_ROUNDING);

    /*!
     * @brief Constructor of the shape::Rectangle
     *
     * @param pos Default position of the shape::Rectangle
     * @param height (optional) The height of the shape::Rectangle
     * @param width (optional) The width of the shape::Rectangle
     * @param rounding (optional) The rounding coefficent of the
     * shape::Rectangle
     */
    Rectangle (const Point& pos, double height = DEFAULT_HEIGHT,
               double width = DEFAULT_WIDTH,
               double rounding = DEFAULT_ROUNDING);

  private:
    double m_height;         /*!< Height of the shape::Rectangle */
    double m_width;          /*!< Width of the shape::Rectangle */
    double m_rounding_coeff; /*!< Coefficient for the corner rounding*/
  };
}
#endif /* !defined(RECTANGLE_HPP) */
