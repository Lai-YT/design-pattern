#ifndef ABSTRACTION_HPP_
#define ABSTRACTION_HPP_

#include <string>

#include "implementation.hpp"


// The Abstraction defines the interface for the "control" part of the two class
// hierarchies. It maintains a reference to an object of the Implementation
// hierarchy and delegates all of the real work to this object.
class Abstraction {
public:
  virtual std::string Operation() const {
    return "Abstraction: Base operation with\n"
           + implementation_.OperationImplementation();
  }

  Abstraction(Implementation& implementation)
    :implementation_(implementation) {}

  virtual ~Abstraction() = default;

protected:
  Implementation& implementation_;
};


// You can extend the Abstraction without changing the Implementation classes.
class ExtendedAbstraction : public Abstraction {
public:
  std::string Operation() const override {
    return "ExtendedAbstraction: Extended operation with\n"
           + implementation_.OperationImplementation();
  }

  using Abstraction::Abstraction;
};


#endif /* end of include guard: ABSTRACTION_HPP_ */
