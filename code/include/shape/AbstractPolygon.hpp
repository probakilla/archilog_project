#ifndef ABSTRACTPOLYGON_HPP
#define ABSTRACTPOLYGON_HPP

#include "AbstractShape.hpp"

#define DEFAULT_COLOR 0xffffff

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
#endif /* !defined(ABSTRACTPOLYGON_HPP) */
