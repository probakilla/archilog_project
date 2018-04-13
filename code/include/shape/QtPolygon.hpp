#ifndef QTPOLYGON_HPP
#define QTPOLYGON_HPP

#include "AbstractPolygon.hpp"

namespace shape
{
  class QtPolygon : public AbstractPolygon
  {
  public:
    /*!
     * @brief Constructor of shape::QtPolygon
     *
     * @param nb_sides (optional) The number of sides of the shape::QtPolygon
     * @param side_length The length  of the shape::QtPolygon
     */
    QtPolygon (int nb_sides = DEFAULT_NB_SIDES,
               double side_length = DEFAULT_SIDE_LENGTH);

    /*!
     * @brief Constructor of shape::QtPolygon
     *
     * @param nb_sides (optionla) The number of sides  of the shape::QtPolygon
     * @param side_length (optional) The length of the sides  of the
     * shape::QtPolygon
     * @param pos The position of the shape::Polygon
     */
    QtPolygon (const Point& pos, int nb_sides = DEFAULT_NB_SIDES,
	       double side_length = DEFAULT_SIDE_LENGTH);

    //!< Default destructor
    ~QtPolygon () = default;

    /*!
     * @brief Draw the shape::QtPolygon
     */
    void draw ();

  private:
  };
}
#endif /* !defined(QTPOLYGON_HPP) */
