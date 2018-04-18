#ifndef ABSTRACTPOLYGON_HPP
#define ABSTRACTPOLYGON_HPP

#include "AbstractShape.hpp"

//!< Default = black color
#define DEFAULT_COLOR 0x00000000

namespace shape
{
  class AbstractPolygon : public AbstractShape
  {
  public:
    //!< Default destructor.
    ~AbstractPolygon () = default;

    //!< Getter on AbstractPolygon::m_color
    hex get_color () const;

    //!< Setter on AbstractPolygon::m_color
    void set_color (hex color);

    //!< Copy operator.
    AbstractPolygon& operator= (const AbstractPolygon& poly);

    //!< Comparison operator.
    bool operator== (const ShapeInterface& shape) override;

    friend boost::serialization::access;
    template <class Archive> void serialize (Archive& ar, unsigned)
    {
      boost::serialization::void_cast_register<AbstractPolygon,
                                               AbstractShape> ();
      boost::serialization::base_object<AbstractShape> (*this);
      ar& m_color;
    }

  protected:
    //!< Empty constructor of shape::AbstractPolygon
    AbstractPolygon ();

    /*!
     * @brief Constructor
     *
     * @param pos Defines the position of the polygon
     * @param color Defines the color of the polygon
     */
    AbstractPolygon (const Point& pos, hex color = DEFAULT_COLOR);

  private:
    hex m_color; //!< Color in hexadecimal of the polygon
  };
}
BOOST_CLASS_EXPORT_KEY (shape::AbstractPolygon);
#endif /* !defined(ABSTRACTPOLYGON_HPP) */
