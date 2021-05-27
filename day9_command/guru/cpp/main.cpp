#include <memory>
#include <utility>

#include "command.hpp"
#include "invoker.hpp"
#include "receiver.hpp"

// The client code can parameterize an invoker with any commands.
int main(int argc, char const *argv[]) {
  auto invoker = std::make_unique<Invoker>();
  invoker->SetOnStart(std::make_unique<SimpleCommand>("Say Hi!"));
  auto receiver = std::make_unique<Receiver>();
  invoker->SetOnFinish(
    std::make_unique<ComplexCommand>(receiver.get(), "Send email", "Save report")
  );
  invoker->DoSomethingImportant();
  // Invoker: Does anybody want something done before I begin?
  // SimpleCommand: See, I can do simple things like printing (Say Hi!)
  // Invoker: ...doing something really important...
  // Invoker: Does anybody want something done after I finish?
  // ComplexCommand: Complex stuff should be done by a receiver object.
  // Receiver: Working on (Send email)

  return 0;
}
