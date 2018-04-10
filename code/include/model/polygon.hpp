#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "abstract_shape.hpp"

#define DEFAULT_NB_SIDES 4
#define DEFAULT_SIDE_LENGTH 10.0

namespace model
{
  class polygon : public abstract_shape
  {
  public:
    /*!
     * @brief Constructor of model::polygon
     *
     * @param pos Default position
     * @param nb_sides Default number of sides
     * @param side_length Default side length
     */
    polygon (point pos, int nb_sides, double side_length);

    //!< Default destructor
    ~polygon () = default;

  private:
    int m_nb_sides;       //!< Number of sides of the model::polygon
    double m_side_length; //!< Length of each side of the model::polygon
  };
}
#endif /* !defined(POLYGON_HPP) */
