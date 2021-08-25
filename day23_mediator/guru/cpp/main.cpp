#include <iostream>

#include "component.hpp"
#include "mediator.hpp"


void ClientCode() {
  Component1 c1;
  Component2 c2;
  ConcreteMediator mediator(c1, c2);

  std::cout << "Client triggers operation A." << '\n';
  c1.DoA();
  std::cout << '\n';

  std::cout << "Client triggers operation D." << '\n';
  c2.DoD();
}


int main(int argc, char const *argv[]) {
  ClientCode();
  // Client triggers operation A.
  // Component1 does A.
  // Mediator reacts on A and triggers following operations:
  // Component2 does C.
  //
  // Client triggers operation D.
  // Component2 does D.
  // Mediator reacts on D and triggers following operations:
  // Component1 does B.
  // Component2 does C.

  return 0;
}
