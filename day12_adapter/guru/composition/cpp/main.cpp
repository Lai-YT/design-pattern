#include <iostream>
#include <memory>

#include "adaptee.hpp"
#include "adapter.hpp"
#include "target.hpp"


void ClientCode(const Target& target) {
  std::cout << target.Request() << '\n';
}


int main(int argc, char const *argv[]) {
  std::cout << "Client: I can work just fine with the Target objects." << '\n';
  auto target = std::make_unique<Target>();
  ClientCode(*target);
  std::cout << '\n';

  std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it." << '\n';
  auto adaptee = std::make_unique<Adaptee>();
  std::cout << "Adaptee: " << adaptee->SpecificRequest() << '\n';
  std::cout << '\n';

  std::cout << "Client: But I can work with it via the Adapter." << '\n';
  auto adapter = std::make_unique<Adapter>(adaptee.get());
  ClientCode(*adapter);
  // Client: I can work just fine with the Target objects.
  // Target: The default target's behavior.
  //
  // Client: The Adaptee class has a weird interface. See, I don't understand it.
  // Adaptee: .eetpadA eht fo roivaheb laicepS
  //
  // Client: But I can work with it via the Adapter.
  // Adapter: (TRANSLATED) Special behavior of the Adaptee.

  return 0;
}
