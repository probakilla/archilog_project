#ifndef QTRECTANGLE_HPP
#define QTRECTANGLE_HPP

#include "Rectangle.hpp"

namespace shape
{
  class QtRectangle : public Rectangle
  {
  public:
    /*!
     * @brief Constructor of shape::QtRectangle
     *
     * @param height (optional) height of the shape::QtRectangle
     * @param width (optional) width of the shape::QtRectangle
     * @param rounding (optional) The rounding coefficent of the
     * shape::QtRectangle
     */
    QtRectangle (double height = DEFAULT_HEIGHT, double width = DEFAULT_WIDTH,
                 double rounding = DEFAULT_ROUNDING);

    /*!
     * @brief Constructor of shape::QtRectangle
     *
     * @param pos The position of the shape::QtRectangle
     * @param height (optional) height of the shape::QtRectangle
     * @param width (optional) width of the shape::QtRectangle
     * @param rounding (optional) The rounding coefficent of the
     * shape::QtRectangle
     */
    QtRectangle (const Point& pos, double height = DEFAULT_HEIGHT,
                 double width = DEFAULT_WIDTH,
                 double rounding = DEFAULT_ROUNDING);

    //!< Default destructor
    ~QtRectangle () = default;

    /*!
     * @brief Draw the shape::QtRectangle
     */
    void draw ();

  private:
  };
}
#endif /* !defined(QTRECTANGLE_HPP) */
