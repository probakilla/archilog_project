#ifndef ALLCOMMANDS_HPP
#define ALLCOMMANDS_HPP

#include "CommandInterface.hpp"

#include <vector>

namespace shape
{
  class AllCommands
  {
  public:
    ~AllCommands ();
    static AllCommands* get_instance ();

    void undo ();

    void redo ();

    void add_undoable (command::CommandInterface* cmd);

    void clear ();

  private:
    AllCommands ();
    static AllCommands* m_instance;
    //!< Vector containing all commands that can be undo
    std::vector<command::CommandInterface*>* m_undoable_commands;
    //!< Vector containing all commands that can be redo
    std::vector<command::CommandInterface*>* m_redoable_commands;
  };
}

#endif /* !define (ALLCOMMANDS_HPP) */
