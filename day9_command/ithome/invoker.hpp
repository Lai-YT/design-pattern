#ifndef INVOKER_HPP_
#define INVOKER_HPP_

#include <forward_list>
#include <iostream>

#include "command.hpp"

// a remote control of the light,
// stores the commands
class Invoker {
public:

  ~Invoker() {
    while (!command_list_.empty()) {
      delete command_list_.front();
      command_list_.pop_front();
    }
  }

  void SetCommand(Command* command) {
    command_list_.push_front(command);
    std::cout << "Waiting for execution..." << '\n';
  }

  void Execute() {
    std::cout << "Do: ";
    if (!command_list_.empty()) {
      command_list_.front()->Execute();
    }
  }

  void Undo() {
    if (!command_list_.empty()) {
      delete command_list_.front();
      command_list_.pop_front();
    }
    std::cout << "Execute the previous command... " << "\n";
    Execute();
  }

private:
  std::forward_list<Command*> command_list_;
};

#endif /* end of include guard: INVOKER_HPP_ */
