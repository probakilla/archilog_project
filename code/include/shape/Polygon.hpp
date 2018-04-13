#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "AbstractPolygon.hpp"

#define DEFAULT_NB_SIDES 4
#define DEFAULT_SIDE_LENGTH 10.0

namespace shape
{
  class Polygon : public AbstractPolygon
  {
  public:
    /*!
     * @brief Constructor of shape::Polygon
     *
     * @param nb_sides The number of sides
     * @param side_length The length of the
     */
    Polygon (int nb_sides = DEFAULT_NB_SIDES,
             double side_length = DEFAULT_SIDE_LENGTH);

    /*!
     * @brief Constructor of shape::Polygon
     *
     * @param nb_sides The number of sides
     * @param side_length The length of the sides
     * @param pos The position of the shape::Polygon
     */
    Polygon (const Point& pos, int nb_sides = DEFAULT_NB_SIDES,
             double side_length = DEFAULT_SIDE_LENGTH);

    //!< Default destructor
    ~Polygon () = default;

    Polygon& operator= (const Polygon& poly);

    bool operator== (const ShapeInterface& shape) override;

  private:
    int m_nb_sides;       //!< The number of sides of the shape::Polygon.
    double m_side_length; //!< The length of each sides of the shape::Polygon.
  };
}
#endif /* !defined(POLYGON_HPP) */
