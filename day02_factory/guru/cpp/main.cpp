#include <iostream>
#include <memory>

#include "creator.hpp"
#include "product.hpp"

// The client code works with an instance of a concrete creator, albeit through
// its base interface. As long as the client keeps working with the creator via
// the base interface, you can pass it any creator's subclass.
void ClientCode(const Creator& creator) {
  std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
            << creator.SomeOperation() << '\n';
}

// The Application picks a creator's type depending on the configuration or
// environment.
int main(int argc, char const *argv[]) {
  std::cout << "App: Launched with the ConcreteCreator1." << '\n';
  auto creator1 = std::make_unique<ConcreteCreator1>();
  ClientCode(*creator1);
  std::cout << '\n';
  std::cout << "App: Launched with the ConcreteCreator2." << '\n';
  auto creator2 = std::make_unique<ConcreteCreator2>();
  ClientCode(*creator2);
  // App: Launched with the ConcreteCreator1.
  // Client: I'm not aware of the creator's class, but it still works.
  // Creator: The same creator's code has just worked with (Result of the ConcreteProduct1)
  //
  // App: Launched with the ConcreteCreator2.
  // Client: I'm not aware of the creator's class, but it still works.
  // Creator: The same creator's code has just worked with (Result of the ConcreteProduct2)

  return 0;
}
