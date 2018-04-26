#ifndef ABSTRACTSHAPE_HPP
#define ABSTRACTSHAPE_HPP

#include "ShapeInterface.hpp"

#include <vector>

#define DEFAULT_X 0
#define DEFAULT_Y 0
//!< Default rotation for the shape
#define DEFAULT_ROTATION 0.0

namespace shape
{
  /*! @brief Structure of a 2D Point */
  struct Point
  {
  public:
    Point (double x = DEFAULT_X, double y = DEFAULT_Y);
    Point (const Point& point);
    ~Point () = default;

    /*! @brief Getter on #m_x */
    double x () const;

    /*! @brief Getter on #m_y */
    double y () const;

    /*! @brief Setter on #m_x */
    void set_x (double x);

    /*! @brief Setter on #m_y */
    void set_y (double y);

    /*! @brief Affectation operator */
    Point& operator= (const Point& point);

    /*! @brief Comparison operator */
    bool operator== (const Point& point) const;

    template <class Point>
    void serialize (Point& ar, const unsigned int version)
    {
      if (version == 0)
        ar& m_x& m_y;
    }

  private:
    double m_x; //!< abscissa
    double m_y; //!< ordinades
  };

  /*! @brief Factorisation for shape classes */
  class AbstractShape : public ShapeInterface
  {
  public:
    /*! @brief Destructor, deletes points members */
    virtual ~AbstractShape () = default;

    virtual bool add_shape (const ShapeInterface& shape);

    virtual bool remove_shape (const ShapeInterface& shape);

    virtual bool operator== (const ShapeInterface& shape) override;

    virtual AbstractShape& operator= (const AbstractShape& shape);

    /*! @brief Getter on #m_position. */
    Point get_position () const;

    /*! @brief Getter on #m_rotation_center. */
    Point get_rotation_center () const;

    /*! @brief Getter on #m_rotation. */
    double get_rotation () const;

    /*! @brief Setter on #m_position. */
    void set_position (const Point& point);

    /*! @brief Setter on #m_rotation_center. */
    void set_rotation_center (const Point& point);

    /*! @brief Setter on #m_rotation. */
    void set_rotation (double angle);

    /*!
     * @brief Translate the #m_position and the #m_rotation_center.
     *
     * Translate the #m_position, Point::m_x by dx and Point::m_y
     * by dy. Translate the #m_rotation_center the same way.
     */
    void translate (double dx, double dy);

    void attach (widget::ObserverInterface* obs);

    void detach (widget::ObserverInterface* obs);

    void notify ();

  protected:
    /*!
     * @brief Empty constructor of shape::AbstractShape.
     *
     * Set the #m_position to (0, 0).
     */
    AbstractShape ();

    /*!
     * @brief Constructor of shape::AbstractShape.
     *
     * @param pos The default #m_position of the shape.
     */
    AbstractShape (const Point& pos, double rotation = DEFAULT_ROTATION);

  private:
    Point m_position;        //!< Current position of the shape.
    Point m_rotation_center; //!< Center of rotation of the shape.
    double m_rotation;       //!< Rotation of the shape.
    std::vector<widget::ObserverInterface*> m_observers;

    friend boost::serialization::access;
    template <class Archive> void serialize (Archive& ar, unsigned)
    {
      ar& boost::serialization::base_object<ShapeInterface> (*this);
      ar& m_position& m_rotation_center& m_rotation;
    }
  };
}
BOOST_CLASS_EXPORT_KEY (shape::AbstractShape);
#endif /* !defined(ABSTRACTSHAPE_HPP) */
