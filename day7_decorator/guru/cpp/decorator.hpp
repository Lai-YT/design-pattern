#ifndef DECORATOR_HPP_
#define DECORATOR_HPP_

#include <memory>
#include <string>
#include <utility>

#include "component.hpp"

// The base Decorator class follows the same interface as the other components.
// The primary purpose of this class is to define the wrapping interface for all
// concrete decorators. The default implementation of the wrapping code might
// include a field for storing a wrapped component and the means to initialize
// it.
class Decorator : public Component {
public:
  // After decoration, the old component should be wrapped and not allowed to
  // take operation, so use unique_ptr and call move
  Decorator(std::unique_ptr<Component>&& component)
    :component_(std::move(component)) {}

  // The Decorator delegates all work to the wrapped component.
  std::string Operation() const override {
    return component_->Operation();
  }

private:
  std::unique_ptr<Component> component_;
};

// Concrete Decorators call the wrapped object and alter its result in some way.
class ConcreteDecoratorA : public Decorator {
public:
  ConcreteDecoratorA(std::unique_ptr<Component>&& component)
    :Decorator(std::move(component)) {}

  // Decorators may call parent implementation of the operation, instead of
  // calling the wrapped object directly. This approach simplifies extension of
  // decorator classes.
  std::string Operation() const override {
    return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
  }
};

// Decorators can execute their behavior either before or after the call to a
// wrapped object.
class ConcreteDecoratorB : public Decorator {
public:
  ConcreteDecoratorB(std::unique_ptr<Component>&& component)
    :Decorator(std::move(component)) {}

  std::string Operation() const override {
    return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
  }
};

#endif /* end of include guard: DECORATOR_HPP_ */
