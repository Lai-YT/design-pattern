#ifndef INVOKER_HPP_
#define INVOKER_HPP_

#include <forward_list>
#include <iostream>
#include <memory>

#include "command.hpp"

// a remote control of the light,
// stores the commands
class Invoker {
public:
  void SetCommand(const Command& command) {
    command_list_.push_front(std::unique_ptr<Command>(command.Clone()));
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
      command_list_.pop_front();
    }
    std::cout << "Execute the previous command... " << "\n";
    Execute();
  }

private:
  std::forward_list<std::unique_ptr<Command>> command_list_;
};


#endif /* end of include guard: INVOKER_HPP_ */
