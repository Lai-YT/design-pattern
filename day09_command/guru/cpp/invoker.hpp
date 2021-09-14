#ifndef INVOKER_HPP_
#define INVOKER_HPP_

#include <memory>
#include <utility>

#include "command.hpp"

// The Invoker is associated with one or several commands. It sends a request to
// the command.
class Invoker {
public:
  Invoker() = default;

  // Initialize commands.
  void SetOnStart(std::unique_ptr<Command> command) {
    on_start_ = std::move(command);
  }

  void SetOnFinish(std::unique_ptr<Command> command) {
    on_finish_ = std::move(command);
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
  std::unique_ptr<Command> on_start_ = nullptr;
  std::unique_ptr<Command> on_finish_ = nullptr;
};


#endif /* end of include guard: INVOKER_HPP_ */
