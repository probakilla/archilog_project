#ifndef COMMANDINTERFACE_HPP
#define COMMANDINTERFACE_HPP

namespace command
{
  class CommandInterface
  {
    void execute ();

		void undo ();
  };
}
#endif /* !defined(COMMANDINTERFACE_HPP) */
