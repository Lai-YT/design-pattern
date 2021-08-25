#include <array>
#include <iostream>
#include <memory>

#include "component.hpp"
#include "visitor.hpp"


// The client code can run visitor operations over any set of elements without
// figuring out their concrete classes. The accept operation directs a call to
// the appropriate operation in the visitor object.
void ClientCode(const std::array<const std::unique_ptr<const Component>, 2>& components, const Visitor& visitor) {
  // ...
  for (const auto& comp : components) {
    comp->Accept(visitor);
  }
  // ...
}


int main(int argc, char const *argv[]) {
  const std::array<const std::unique_ptr<const Component>, 2> components{
    std::make_unique<const ConcreteComponentA>(),
    std::make_unique<const ConcreteComponentB>()
  };

  std::cout << "The client code works with all visitors via the base Visitor interface:" << '\n';
  const ConcreteVisitor1 visitor_1;
  ClientCode(components, visitor_1);

  std::cout << "It allows the same client code to work with different types of visitors:" << '\n';
  const ConcreteVisitor2 visitor_2;
  ClientCode(components, visitor_2);
  // The client code works with all visitors via the base Visitor interface:
  // A + ConcreteVisitor1
  // B + ConcreteVisitor1
  // It allows the same client code to work with different types of visitors:
  // A + ConcreteVisitor2
  // B + ConcreteVisitor2

  return 0;
}
