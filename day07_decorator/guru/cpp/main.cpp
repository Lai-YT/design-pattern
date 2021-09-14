#include <iostream>
#include <memory>
#include <utility>

#include "component.hpp"
#include "decorator.hpp"

// The client code works with all objects using the Component interface. This
// way it can stay independent of the concrete classes of components it works
// with.
void ClientCode(const Component& component) {
  // Since ClientCode doesn't handle anything about lifetime and should only
  // observe, passes Component as a const reference.
  std::cout << "Result: " << component.Operation() << '\n';
}


int main(int argc, char const *argv[]) {
  // This way the client code can support both simple components...
  auto simple = std::make_unique<ConcreteComponent>();
  std::cout << "Client: I've got a simple component:" << '\n';
  ClientCode(*simple);
  
  std::cout << '\n';

  // ...as well as decorated ones.
  //
  // Note how decorators can wrap not only simple components but the other
  // decorators as well.
  auto decorator1 = std::make_unique<ConcreteDecoratorA>(std::move(simple));
  auto decorator2 = std::make_unique<ConcreteDecoratorB>(std::move(decorator1));
  std::cout << "Client: Now I've got a decorated component:" << '\n';
  ClientCode(*decorator2);
  // Client: I've got a simple component:
  // Result: ConcreteComponent
  //
  // Client: Now I've got a decorated component:
  // Result: ConcreteDecoratorB(ConcreteDecoratorA(ConcreteComponent))

  return 0;
}
