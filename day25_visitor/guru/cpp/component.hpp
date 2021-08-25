#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <string>


class Visitor;


// The Component interface declares an `accept` method that should take the base
// visitor interface as an argument.
class Component {
public:
  virtual void Accept(const Visitor& visitor) const = 0;

  virtual ~Component() = default;
};


// Each Concrete Component must implement the `Accept` method in such a way that
// it calls the visitor's method corresponding to the component's class.
class ConcreteComponentA : public Component {
public:
  // Note that we're calling `VisitConcreteComponentA`, which matches the
  // current class name. This way we let the visitor know the class of the
  // component it works with.
  void Accept(const Visitor& visitor) const override;

  // Concrete Components may have special methods that don't exist in their base
  // class or interface. The Visitor is still able to use these methods since
  // it's aware of the component's concrete class.
  std::string ExclusiveMethodOfConcreteComponentA() const;
};


class ConcreteComponentB : public Component {
public:
  // Same here: VisitConcreteComponentB => ConcreteComponentB
  void Accept(const Visitor& visitor) const override;

  std::string SpecialMethodOfConcreteComponentB() const;
};


#endif /* end of include guard: COMPONENT_HPP_ */
