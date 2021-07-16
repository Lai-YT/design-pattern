#include <memory>

#include "context.hpp"
#include "state.hpp"


void ClientCode() {
  auto context = Context::CreateSharedWithInitState(std::make_shared<ConcreteStateA>());
  context->Request1();
  context->Request2();
}


int main(int argc, char const *argv[]) {
  ClientCode();
  // Context: Transition to ConcreteStateA.
  // ConcreteStateA handles Request1.
  // ConcreteStateA wants to change the state of the context.
  // Context: Transition to ConcreteStateB.
  // ConcreteStateB handles Request2.
  // ConcreteStateB wants to change the state of the context.
  // Context: Transition to ConcreteStateA.

  return 0;
}
