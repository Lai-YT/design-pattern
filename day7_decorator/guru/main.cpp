#include <iostream>

#include "component.hpp"
#include "decorator.hpp"

// The client code works with all objects using the Component interface. This
// way it can stay independent of the concrete classes of components it works
// with.
void ClientCode(Component* component) {
  std::cout << "Result: " << component->Operation() << '\n';
}


int main(int argc, char const *argv[]) {
  // This way the client code can support both simple components...
  Component* simple = new ConcreteComponent;
  std::cout << "Client: I've got a simple component:" << '\n';
  ClientCode(simple);
  std::cout << '\n';

  // ...as well as decorated ones.
  //
  // Note how decorators can wrap not only simple components but the other
  // decorators as well.
  Component* decorator1 = new ConcreteDecoratorA(simple);
  Component* decorator2 = new ConcreteDecoratorB(decorator1);
  std::cout << "Client: Now I've got a decorated component:" << '\n';
  ClientCode(decorator2);
  std::cout << '\n';
  // Client: I've got a simple component:
  // Result: ConcreteComponent
  //
  // Client: Now I've got a decorated component:
  // Result: ConcreteDecoratorB(ConcreteDecoratorA(ConcreteComponent))

  // delete in reverse order
  delete decorator2;
  delete decorator1;
  delete simple;

  return 0;
}
