#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "AbstractPolygon.hpp"

#define DEFAULT_HEIGHT 8.0
#define DEFAULT_WIDTH 8.0
#define DEFAULT_ROUNDING 0.0

namespace shape
{
  class Rectangle : public AbstractPolygon
  {
  public:
    /*!
     * @brief Constructor of the shape::Rectangle
     *
     * @param pos Default position
     * @param height Default height
     * @param width Default width
     */
    Rectangle (double height = DEFAULT_HEIGHT, double width = DEFAULT_WIDTH,
               double rounding = DEFAULT_ROUNDING);

    /*!
     * @brief Constructor of the shape::Rectangle
     *
     * @param pos Default position
     * @param height Default height
     * @param width Default width
     * @param rounding Default rounding coefficent
     */
    Rectangle (const Point& pos, double height = DEFAULT_HEIGHT,
               double width = DEFAULT_WIDTH,
               double rounding = DEFAULT_ROUNDING);

    //!< Default destructor.
    ~Rectangle () = default;

    Rectangle& operator= (const Rectangle& rec);

    bool operator== (const ShapeInterface& shape) override;

  protected:
    double get_height () const;

    double get_width () const;

    double get_rounding_coeff () const;

  private:
    double m_height;         /*!< Height of the shape::Rectangle */
    double m_width;          /*!< Width of the shape::Rectangle */
    double m_rounding_coeff; /*!< Coefficient for the corner rounding*/
  };
}
#endif /* !defined(RECTANGLE_HPP) */
