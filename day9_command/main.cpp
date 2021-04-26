#include "command.hpp"
#include "invoker.hpp"
#include "receiver.hpp"

// The client code can parameterize an invoker with any commands.
int main(int argc, char const *argv[]) {
  Invoker *invoker = new Invoker;
  invoker->SetOnStart(new SimpleCommand("Say Hi!"));
  Receiver *receiver = new Receiver;
  invoker->SetOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));
  invoker->DoSomethingImportant();

  delete invoker;
  delete receiver;

  return 0;
}
