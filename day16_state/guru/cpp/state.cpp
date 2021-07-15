#include <iostream>

#include "context.hpp"
#include "state.hpp"


void State::SetContext(Context* const context) {
  this->context_ = context;
}

void ConcreteStateA::Handle1() {
  std::cout << "ConcreteStateA handles Request1." << '\n';
  std::cout << "ConcreteStateA wants to change the state of the context." << '\n';
  this->context_->TransitionTo(new ConcreteStateB());
}

void ConcreteStateA::Handle2() {
  std::cout << "ConcreteStateA handles Request2." << '\n';
}

void ConcreteStateB::Handle1() {
  std::cout << "ConcreteStateB handles Request1." << '\n';
}

void ConcreteStateB::Handle2() {
  std::cout << "ConcreteStateB handles Request2." << '\n';
  std::cout << "ConcreteStateB wants to change the state of the context." << '\n';
  this->context_->TransitionTo(new ConcreteStateA());
}
