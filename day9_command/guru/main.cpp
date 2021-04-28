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
  // Invoker: Does anybody want something done before I begin?
  // SimpleCommand: See, I can do simple things like printing (Say Hi!)
  // Invoker: ...doing something really important...
  // Invoker: Does anybody want something done after I finish?
  // ComplexCommand: Complex stuff should be done by a receiver object.
  // Receiver: Working on (Send email)
  
  delete invoker;
  delete receiver;

  return 0;
}
