#ifndef INVOKER_HPP_
#define INVOKER_HPP_

#include "command.hpp"

// The Invoker is associated with one or several commands. It sends a request to
// the command.
class Invoker {
public:
  Invoker() = default;

  ~Invoker() {
    delete on_start_;
    delete on_finish_;
  }
  // Initialize commands.
  void SetOnStart(Command* command) {
    on_start_ = command;
  }

  void SetOnFinish(Command* command) {
    on_finish_ = command;
  }
  // The Invoker does not depend on concrete command or receiver classes. The
  // Invoker passes a request to a receiver indirectly, by executing a command.
  void DoSomethingImportant() {
    std::cout << "Invoker: Does anybody want something done before I begin?" << '\n';
    if (on_start_) {
      on_start_->Execute();
    }
    std::cout << "Invoker: ...doing something really important..." << '\n';
    std::cout << "Invoker: Does anybody want something done after I finish?" << '\n';
    if (on_finish_) {
      on_finish_->Execute();
    }
  }
  
private:
  Command *on_start_ = nullptr;
  Command *on_finish_ = nullptr;
};

#endif /* end of include guard: INVOKER_HPP_ */
