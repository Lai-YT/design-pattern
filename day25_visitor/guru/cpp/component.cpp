#include "component.hpp"

#include <string>

#include "visitor.hpp"


void ConcreteComponentA::Accept(const Visitor& visitor) const {
  visitor.VisitConcreteComponentA(*this);
}

std::string ConcreteComponentA::ExclusiveMethodOfConcreteComponentA() const {
  return "A";
}


void ConcreteComponentB::Accept(const Visitor& visitor) const {
  visitor.VisitConcreteComponentB(*this);
}

std::string ConcreteComponentB::SpecialMethodOfConcreteComponentB() const {
  return "B";
}
