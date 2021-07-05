#include <iostream>

#include "prototype_factory.hpp"
#include "prototype.hpp"


void ClientCode(const PrototypeFactory& prototype_factory) {
  std::cout << "Let's create a Prototype 1." << '\n';
  auto prototype_1 = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
  prototype_1->Method();
  std::cout << '\n';

  std::cout << "Let's create a Prototype 2." << '\n';
  auto prototype_2 = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
  prototype_2->Method();
}


int main(int argc, char const *argv[]) {
  PrototypeFactory prototype_factory;
  ClientCode(prototype_factory);
  // Let's create a Prototype 1.
  // Call Method from PROTOTYPE_1 with field: 50
  //
  // Let's create a Prototype 2.
  // Call Method from PROTOTYPE_2 with field: 60

  return 0;
}
