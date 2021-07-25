#include <iostream>
#include <memory>

#include "component.hpp"


// The client code works with all of the components via the base interface.
void ClientCode1(const Component* const component) {
  // ...
  std::cout << "Result: " << component->Operation() << ".\n";
  // ...
}

// Thanks to the fact that the child-management operations are declared in the
// base Component class, the client code can work with any component, simple or
// complex, without depending on their concrete classes.
void ClientCode2(Component* const component_1, Component* const component_2) {
  // ...
  if (component_1->IsComposite()) {
    component_1->Add(component_2);
  }
  std::cout << "Result: " << component_1->Operation() << ".\n";
  // ...
}


int main(int argc, char const *argv[]) {
  // This way the client code can support the simple leaf components...
  auto simple = std::make_shared<Leaf>();
  std::cout << "Client: I've got a simple component." << '\n';
  ClientCode1(simple.get());
  std::cout << '\n';

  // ...as well as the complex composites.
  auto tree = std::make_shared<Composite>();

  auto branch_1 = std::make_shared<Composite>();
  auto leaf_1 = std::make_shared<Leaf>();
  auto leaf_2 = std::make_shared<Leaf>();
  branch_1->Add(leaf_1.get());
  branch_1->Add(leaf_2.get());

  auto branch_2 = std::make_shared<Composite>();
  auto leaf_3 = std::make_shared<Leaf>();
  branch_2->Add(leaf_3.get());

  tree->Add(branch_1.get());
  tree->Add(branch_2.get());
  std::cout << "Client: Now I've got a composite tree." << '\n';
  ClientCode1(tree.get());
  std::cout << '\n';

  std::cout << "Client: I don't need to check the components classes even when managing the tree." << '\n';
  ClientCode2(tree.get(), simple.get());
  // Client: I've got a simple component.
  // Result: Leaf.
  //
  // Client: Now I've got a composite tree.
  // Result: Branch(Branch(Leaf+Leaf)+Branch(Leaf)).
  //
  // Client: I don't need to check the components classes even when managing the tree.
  // Result: Branch(Branch(Leaf+Leaf)+Branch(Leaf)+Leaf).

  return 0;
}
