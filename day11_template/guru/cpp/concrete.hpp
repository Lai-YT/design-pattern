#ifndef CONCRETE_HPP_
#define CONCRETE_HPP_

#include <iostream>

#include "abstract.hpp"

// Concrete classes have to implement all abstract operations of the base class.
// They can also override some operations with a default implementation.
class ConcreteClass1 : public AbstractClass {
protected:
  void RequiredOperation1() const override {
    std::cout << "ConcreteClass1 says: implemented Operation1." << '\n';
  }

  void RequiredOperation2() const override {
    std::cout << "ConcreteClass1 says: implemented Operation2." << '\n';
  }
};

// Usually, concrete classes override only a fraction of base class' operations.
class ConcreteClass2 : public AbstractClass {
protected:
  void RequiredOperation1() const override {
    std::cout << "ConcreteClass2 says: implemented Operation1." << '\n';
  }

  void RequiredOperation2() const override {
    std::cout << "ConcreteClass2 says: implemented Operation2." << '\n';
  }

  void Hook1() const override {
    std::cout << "ConcreteClass2 says: Overriden Hook1." << '\n';
  }
};


#endif /* end of include guard: CONCRETE_HPP_ */
