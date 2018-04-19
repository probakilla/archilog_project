#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "AbstractPolygon.hpp"
#include "Memento.hpp"

#define DEFAULT_NB_SIDES 5
#define DEFAULT_SIDE_LENGTH 50.0

namespace shape
{
  class Polygon : public AbstractPolygon
  {
  public:
    /*!
     * @brief Constructor of shape::Polygon
     *
     * @param nb_sides (optional) The number of sides
     * @param side_length (optional) The length of the
     * shape::Polygon
     */
    Polygon (int nb_sides = DEFAULT_NB_SIDES,
             double side_length = DEFAULT_SIDE_LENGTH);

    /*!
     * @brief Constructor of shape::Polygon
     *
     * @param nb_sides The number of sides
     * @param side_length (optional) The length of the sides
     * @param pos (optional) The position of the shape::Polygon
     */
    Polygon (const Point& pos, int nb_sides = DEFAULT_NB_SIDES,
             double side_length = DEFAULT_SIDE_LENGTH);
    //!< Default destructor
    ~Polygon () = default;

    //!< Copy operator.
    Polygon& operator= (const Polygon& poly);

    //!< Comparison operator.
    bool operator== (const ShapeInterface& shape) override;

    //!< Getter on nb_sides.
    int get_nb_sides () const;

    //!< Getter on side length.
    double get_side_length () const;

    //! Setter on nb_sides.
    void set_nb_sides (int nb_sides);

    //! Setter on side length.
    void set_side_length (double side_length);

    /*!
     * @brief Create a Memento of shape::polygon.
     *
     * Create a Memento of shape::polygon, that store a copy
     * of the object shape::polygon.
     * @return The memento of shape::polygon.
     */
    Memento<Polygon> create_memento () const;

    /*!
     * @brief Restaure the state of shape::polygon.
     *
     * Restaure the state of shape::polygon with the one in the
     * shape::Memento.
     * @param m The memento used to restaure the state.
     */
    void set_memento (Memento<Polygon> m);

  private:
    int m_nb_sides;       //!< The number of sides of the shape::Polygon.
    double m_side_length; //!< The length of each sides of the shape::Polygon.

    friend class boost::serialization::access;
    template <class Archive> void serialize (Archive& ar, unsigned)
    {
      boost::serialization::base_object<AbstractPolygon> (*this);
      ar& m_nb_sides& m_side_length;
    }
  };
}
BOOST_CLASS_EXPORT_KEY (shape::Polygon);
#endif /* !defined(POLYGON_HPP) */
