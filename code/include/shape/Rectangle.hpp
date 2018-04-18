#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "AbstractPolygon.hpp"
#include "Memento.hpp"

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

    //!< Setter on height.
    void set_height (double height);

    //!< Setter on width.
    void set_width (double width);

    //!< Setter on rounding coeff.
    void set_rounding_coeff (double rounding_coeff);

    /*!
     * @brief Create a Memento of shape::rectangle.
     *
     * Create a Memento of shape::rectangle, that store a copy
     * of the object shape::rectangle.
     * @return The memento of shape::rectangle.
     */
    Memento<Rectangle> create_memento () const;

    /*!
     * @brief Restaure the state of shape::rectangle.
     *
     * Restaure the state of shape::rectangle with the one in the
     * shape::Memento.
     * @param m The memento used to restaure the state.
     */
    void set_memento (Memento<Rectangle> m);

    template <class Archive>
    void serialize (Archive& ar, const unsigned int version)
    {
      boost::serialization::void_cast_register<Rectangle, AbstractPolygon> ();
      boost::serialization::base_object<AbstractPolygon> (*this);
      if (version == 0)
        ar& m_height& m_width& m_rounding_coeff;
    }

  private:
    double m_height;         /*!< Height of the shape::Rectangle */
    double m_width;          /*!< Width of the shape::Rectangle */
    double m_rounding_coeff; /*!< Coefficient for the corner rounding*/
  };
}
BOOST_CLASS_EXPORT_KEY (shape::Rectangle);
#endif /* !defined(RECTANGLE_HPP) */
