#include <iostream>
#include <string>

#include "component.hpp"
#include "mediator.hpp"


void BaseComponent::SetMediator(Mediator* const mediator) {
  mediator_ = mediator;
}

BaseComponent::BaseComponent(Mediator* const mediator)
  :mediator_(mediator) {}


void Component1::DoA() const {
  std::cout << "Component1 does A." << '\n';
  if (mediator_) {
    mediator_->Notify(this, "A");
  }
}

void Component1::DoB() const {
  std::cout << "Component1 does B." << '\n';
  if (mediator_) {
    mediator_->Notify(this, "B");
  }
}


void Component2::DoC() const {
  std::cout << "Component2 does C." << '\n';
  if (mediator_) {
    mediator_->Notify(this, "C");
  }
}

void Component2::DoD() const {
  std::cout << "Component2 does D." << '\n';
  if (mediator_) {
    mediator_->Notify(this, "D");
  }
}
