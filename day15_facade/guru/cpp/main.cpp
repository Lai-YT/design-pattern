#include <iostream>
#include <memory>
#include <utility>  // std::move

#include "facade.hpp"
#include "subsystem.hpp"


// The client code works with complex subsystems through a simple interface
// provided by the Facade. When a facade manages the lifecycle of the subsystem,
// the client might not even know about the existence of the subsystem. This
// approach lets you keep the complexity under control.
void ClientCode(const Facade& facade) {
  std::cout << facade.Operation();
}


// The client code may have some of the subsystem's objects already created. In
// this case, it might be worthwhile to initialize the Facade with these objects
// instead of letting the Facade create new instances.
int main(int argc, char const *argv[]) {
  auto subsystem1 = std::make_unique<Subsystem1>();
  auto subsystem2 = std::make_unique<Subsystem2>();
  Facade facade(std::move(subsystem1), std::move(subsystem2));
  ClientCode(facade);
  // Facade initializes subsystems.
  // Subsystem1: Ready!
  // Subsystem2: Get ready!
  // Facade orders subsystems to perform the action.
  // Subsystem1: Go!
  // Subsystem2: Fire!

  return 0;
}
