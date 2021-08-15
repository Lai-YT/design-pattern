#ifndef MEDIATOR_HPP_
#define MEDIATOR_HPP_

#include <string>

#include "component.hpp"

class BaseComponent;
class Component1;
class Component2;


// The Mediator interface declares a method used by components to notify the
// mediator about various events. The Mediator may react to these events and
// pass the execution to other components.
class Mediator {
public:
  virtual void Notify(const BaseComponent* const sender, const std::string& event) const = 0;
};


// Concrete Mediators implement cooperative behavior by coordinating several
// components.
class ConcreteMediator : public Mediator {
public:
  void Notify(const BaseComponent* const sender, const std::string& event) const override;

  ConcreteMediator(Component1* const component_1, Component2* const component_2);

private:
  Component1* component_1_;
  Component2* component_2_;
};


#endif /* end of include guard: MEDIATOR_HPP_ */
