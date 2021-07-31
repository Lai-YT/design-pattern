#ifndef IMPLEMENTATION_HPP_
#define IMPLEMENTATION_HPP_

#include <string>


// The Implementation defines the interface for all implementation classes. It
// doesn't have to match the Abstraction's interface. In fact, the two
// interfaces can be entirely different. Typically the Implementation interface
// provides only primitive operations, while the Abstraction defines higher-
// level operations based on those primitives.
class Implementation {
public:
  virtual std::string OperationImplementation() const = 0;
  virtual ~Implementation() = default;
};


// Each Concrete Implementation corresponds to a specific platform and
// implements the Implementation interface using that platform's API.
class ConcreteImplementationA : public Implementation {
public:
  std::string OperationImplementation() const override {
    return "ConcreteImplementationA: Here's the result on the platform A.";
  }
};

class ConcreteImplementationB : public Implementation {
public:
  std::string OperationImplementation() const override {
    return "ConcreteImplementationB: Here's the result on the platform B.";
  }
};


#endif /* end of include guard: IMPLEMENTATION_HPP_ */
