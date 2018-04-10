#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

namespace view
{
  class main_window
  {
  public:
    main_window ();
    virtual ~main_window () = default;

    void run (int argc, char** argv);

  private:
  };
}
#endif /* !defined(MAIN_WINDOW_HPP) */
