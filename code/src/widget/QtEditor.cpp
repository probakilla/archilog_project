#include "QtEditor.hpp"

#include <QColorDialog>
#include <QInputDialog>
#include <string>

namespace widget
{
  static void add_dialog (QVBoxLayout* layout, std::string name)
  {
    const char* c = name.c_str ();
    QInputDialog dialog;
    dialog.setLabelText (c);
    layout->addWidget (&dialog);
  }

  QtEditor::QtEditor ()
  {
    m_editor = new QWidget;
  }

  QtEditor::~QtEditor () {}

  void QtEditor::add_color ()
  {
    QColorDialog dialog;
    m_layout.addWidget (&dialog);
  }

  void QtEditor::add_width ()
  {
    add_dialog (&m_layout, "Shape width");
  }

  void QtEditor::add_height ()
  {
    add_dialog (&m_layout, "Shape height");
  }

  void QtEditor::add_rounding ()
  {
    add_dialog (&m_layout, "Shape rounding coefficient");
  }

  void QtEditor::add_nb_sides ()
  {
    add_dialog (&m_layout, "Shape number of sides");
  }

  void QtEditor::add_side_length ()
  {
    add_dialog (&m_layout, "Shape side length");
  }

  void QtEditor::add_rotation_center ()
  {
    add_dialog (&m_layout, "Shape rotation center abscissa");
    add_dialog (&m_layout, "Shape rotation center ordinate");
  }

  QWidget* QtEditor::get_result ()
  {
    return m_editor;
  }
}
