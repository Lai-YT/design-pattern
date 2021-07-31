#include <iostream>

#include "abstraction.hpp"
#include "implementation.hpp"


// Except for the initialization phase, where an Abstraction object gets linked
// with a specific Implementation object, the client code should only depend on
// the Abstraction class. This way the client code can support any abstraction-
// implementation combination.
void ClientCode(const Abstraction& abstraction) {
  // ...
  std::cout << abstraction.Operation() << '\n';
  // ...
}
// The client code should be able to work with any pre-configured abstraction-
// implementation combination.


int main(int argc, char const *argv[]) {
  ConcreteImplementationA implementation_a;
  Abstraction abstraction(implementation_a);
  ClientCode(abstraction);
  std::cout << '\n';

  ConcreteImplementationB implementation_b;
  ExtendedAbstraction extended_abstraction(implementation_b);
  ClientCode(extended_abstraction);
  // Abstraction: Base operation with
  // ConcreteImplementationA: Here's the result on the platform A.
  //
  // ExtendedAbstraction: Extended operation with
  // ConcreteImplementationB: Here's the result on the platform B.

  return 0;
}
