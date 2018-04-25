#ifndef QTPOLYGON_HPP
#define QTPOLYGON_HPP

#include "Polygon.hpp"

#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>

#define MAX_VALUE 1024.0

namespace widget
{
  class QtPolygon : public QGraphicsPolygonItem
  {
  public:
    QtPolygon (shape::Polygon poly);
    ~QtPolygon ();

    void contextMenuEvent (QGraphicsSceneContextMenuEvent* event);

  private slots:

  private:
    /*!
     * @brief Show the dialog for shape editing.
     *
     * Show a dialog for the selection of a double value
     * @param name The name of the dialog
     * @param def_val The default value of the dialog
     * @param max_val The maximumu value possible for the dialog
     * @return The selected value if correct, -1.0 if there is an error
     */
    double input_dialog (const QString& name, double def_val,
                         double max_val = MAX_VALUE) const;

    shape::Polygon m_poly;
  };
}

#endif // !defined QTPOLYGON_HPP
