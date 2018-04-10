#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "abstract_shape.hpp"

#define DEFAULT_HEIGHT 8.0
#define DEFAULT_WIDTH 8.0
#define DEFAULT_ROUNDING 0.0

namespace model
{
  class rectangle : public abstract_shape
  {
  public:
    /*!
     * @brief Constructor of the model::rectangle
     *
     * @param pos Default position
     * @param height Default height
     * @param width Default width
     * @param rounding Default rounding coefficent
     */
    rectangle (point pos, double height = DEFAULT_HEIGHT,
               double width = DEFAULT_WIDTH,
               double rounding = DEFAULT_ROUNDING);

    //!< Default destructor.
    ~rectangle () = default;

  private:
    double m_height;         /*!< Height of the model::rectangle */
    double m_width;          /*!< Width of the model::rectangle */
    double m_rounding_coeff; /*!< Coefficient for the corner rounding*/
  };
}
#endif /* !defined(RECTANGLE_HPP) */
