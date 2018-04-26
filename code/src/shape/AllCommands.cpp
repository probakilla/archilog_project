#include "AllCommands.hpp"

#include "RectColorCommand.hpp"
#include "RectHeightCommand.hpp"
#include "RectWidthCommand.hpp"

#include <cstddef>
namespace shape
{
  AllCommands* AllCommands::m_instance = NULL;

  AllCommands::AllCommands ()
  {
    m_undoable_commands = new std::vector<command::CommandInterface*>;
    m_redoable_commands = new std::vector<command::CommandInterface*>;
  }

  AllCommands::~AllCommands () {}

  AllCommands* AllCommands::get_instance ()
  {
    if (m_instance == NULL)
    {
      m_instance = new AllCommands ();
    }
    return m_instance;
  }

  void AllCommands::undo ()
  {
    if (m_undoable_commands->size () == 0)
      return;
    command::CommandInterface* cmd = m_undoable_commands->back ();
    cmd->undo ();
    m_redoable_commands->push_back (cmd);
    m_undoable_commands->pop_back ();
  }

  void AllCommands::redo ()
  {
    if (m_redoable_commands->size () == 0)
      return;
    command::CommandInterface* cmd = m_redoable_commands->back ();
    cmd->execute ();
    m_undoable_commands->push_back (cmd);
    m_redoable_commands->pop_back ();
  }

  void AllCommands::add_undoable (command::CommandInterface* cmd)
  {
    m_undoable_commands->push_back (cmd);
    m_redoable_commands->clear ();
    cmd->execute ();
  }

  void AllCommands::clear ()
  {
    m_undoable_commands->clear ();
    m_redoable_commands->clear ();
  }
}
