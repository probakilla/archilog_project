#ifndef QTEDITOR_HPP
#define QTEDITOR_HPP

#include "EditorInterface.hpp"

#include <QWidget>
#include <QVBoxLayout>

namespace widget
{
  class QtEditor : public EditorInterface
  {
  public:
    /*!
     * @brief Empty constructor of widget::QtEditor
     *
     * Will initialize the QWidget member.
     */
    QtEditor ();

    //!< This destructor don't deletes the QWidget member
    ~QtEditor ();

    void add_color ();

    void add_width ();

    void add_height ();

    void add_rounding ();

    void add_nb_sides ();

    void add_side_length ();

    void add_rotation_center ();

    /*!
     * @brief Return the result of the builder.
     *
     * The result is set by functions defined in the EditorInterface
     */
    QWidget* get_result ();

  private:
    //!< The window where the layout will be
    QWidget* m_editor;
    //!< The layout where the option choosers will be.
    QVBoxLayout m_layout;
  };
}
#endif /* !defined(QTEDITOR_HPP) */
