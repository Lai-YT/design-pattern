#ifndef ABSTRACT_HPP_
#define ABSTRACT_HPP_

#include <iostream>

// The Abstract Class defines a template method that contains a skeleton of some
// algorithm, composed of calls to (usually) abstract primitive operations.
//
// Concrete subclasses should implement these operations, but leave the template
// method itself intact.
class AbstractClass {
public:
  // The template method defines the skeleton of an algorithm.
  void TemplateMethod() const {
    this->BaseOperation1();
    this->RequiredOperation1();
    this->BaseOperation2();
    this->Hook1();
    this->RequiredOperation2();
    this->BaseOperation3();
    this->Hook2();
  }

protected:
  // These operations already have implementations.
  void BaseOperation1() const {
    std::cout << "AbstractClass says: I am doing the bulk of the work." << '\n';
  }

  void BaseOperation2() const {
    std::cout << "AbstractClass says: But I let subclasses override some operations." << '\n';
  }

  void BaseOperation3() const {
    std::cout << "AbstractClass says: But I am doing the bulk of the work anyway." << '\n';
  }

  // These operations have to be implemented in subclasses.
  virtual void RequiredOperation1() const = 0;
  virtual void RequiredOperation2() const = 0;

  // These are "hooks." Subclasses may override them, but it's not mandatory
  // since the hooks already have default (but empty) implementation. Hooks
  // provide additional extension points in some crucial places of the
  // algorithm.
  virtual void Hook1() const {};
  virtual void Hook2() const {};

};


#endif /* end of include guard: ABSTRACT_HPP_ */
