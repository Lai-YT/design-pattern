#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <string>

// The base Component interface defines operations that can be altered by
// decorators.
class Component {
public:
  virtual ~Component() = default;
  virtual std::string Operation() const = 0;
};

// Concrete Components provide default implementations of the operations. There
// might be several variations of these classes.
class ConcreteComponent : public Component {
public:
  std::string Operation() const override {
    return "ConcreteComponent";
  }
};

#endif /* end of include guard: COMPONENT_HPP_ */
