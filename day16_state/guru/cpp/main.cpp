#include "context.hpp"
#include "state.hpp"


void ClientCode() {
  Context* context = new Context(new ConcreteStateA());
  context->Request1();
  context->Request2();
  delete context;
}


int main(int argc, char const *argv[]) {
  ClientCode();
  // Context: Transition to 14ConcreteStateA.
  // ConcreteStateA handles Request1.
  // ConcreteStateA wants to change the state of the context.
  // Context: Transition to 14ConcreteStateB.
  // ConcreteStateB handles Request2.
  // ConcreteStateB wants to change the state of the context.
  // Context: Transition to 14ConcreteStateA.

  return 0;
}
