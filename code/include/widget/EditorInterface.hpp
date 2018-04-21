#ifndef EDITORINTERFACE_HPP
#define EDITORINTERFACE_HPP

namespace widget
{
  /*!
   * @brief Interface for the Shape editing window
   *
   * This interface defines the builder interface for the shape editing window
   */
  class EditorInterface
  {
  public:
    //!< Default destructor
    virtual ~EditorInterface () = default;

    //!< Create the window where all selector will be
    virtual void create_window () = 0;

    //!< Add a color chooser in the window
    virtual void add_color () = 0;

    //!< Add a width chooser in the window
    virtual void add_width () = 0;

    //!< Add a height chooser in the window
    virtual void add_height () = 0;

    //!< Add a rounding coefficient chooser in the window
    virtual void add_rounding () = 0;

    //!< Add a number of sides chooser in the window
    virtual void add_nb_sides () = 0;

    //!< Add a side length chooser in the window
    virtual void add_side_length () = 0;

    //!< Add a rotation center chooser in the window
    virtual void add_rotation_center () = 0;
  };
}

#endif // !defined EDITORINTERFACE_HPP
