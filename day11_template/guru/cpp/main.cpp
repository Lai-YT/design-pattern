#include "abstract.hpp"
#include "concrete.hpp"

// The client code calls the template method to execute the algorithm. Client
// code does not have to know the concrete class of an object it works with, as
// long as it works with objects through the interface of their base class.
void ClientCode(AbstractClass* cls) {
  cls->TemplateMethod();
}


int main(int argc, char const *argv[]) {
  std::cout << "Same client code can work with different subclasses:" << '\n';
  ConcreteClass1 concrete_class_1;
  ClientCode(&concrete_class_1);

  std::cout << '\n';

  std::cout << "Same client code can work with different subclasses:" << '\n';
  ConcreteClass2 concrete_class_2;
  ClientCode(&concrete_class_2);
  // Same client code can work with different subclasses:
  // AbstractClass says: I am doing the bulk of the work.
  // ConcreteClass1 says: implemented Operation1.
  // AbstractClass says: But I let subclasses override some operations.
  // ConcreteClass1 says: implemented Operation2.
  // AbstractClass says: But I am doing the bulk of the work anyway.
  //
  // Same client code can work with different subclasses:
  // AbstractClass says: I am doing the bulk of the work.
  // ConcreteClass2 says: implemented Operation1.
  // AbstractClass says: But I let subclasses override some operations.
  // ConcreteClass2 says: Overriden Hook1.
  // ConcreteClass2 says: implemented Operation2.
  // AbstractClass says: But I am doing the bulk of the work anyway.

  return 0;
}
