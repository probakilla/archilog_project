#ifndef COMMANDINTERFACE_HPP
#define COMMANDINTERFACE_HPP
namespace command
{
  class CommandInterface
  {
  public:
    virtual void execute () = 0;

    virtual void undo () = 0;
  };
}
#endif /* !defined(COMMANDINTERFACE_HPP) */
