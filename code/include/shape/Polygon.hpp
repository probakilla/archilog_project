#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "AbstractShape.hpp"

#define DEFAULT_NB_SIDES 4
#define DEFAULT_SIDE_LENGTH 10.0

namespace shape
{
  class Polygon : public AbstractShape
  {
  public:
    /*!
     * @brief Constructor of shape::Polygon
     *
     * @param pos Default position
     * @param nb_sides Default number of sides
     * @param side_length Default side length
     */
    Polygon (Point pos, int nb_sides, double side_length);

    //!< Default destructor
    ~Polygon () = default;

  private:
    int m_nb_sides;       //!< Number of sides of the shape::Polygon
    double m_side_length; //!< Length of each side of the shape::Polygon
  };
}
#endif /* !defined(POLYGON_HPP) */
