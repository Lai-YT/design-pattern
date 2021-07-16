#include <iostream>
#include <memory>

#include "context.hpp"
#include "state.hpp"


void State::SetContext(std::weak_ptr<Context> context) {
  this->context_ = context;
}

void ConcreteStateA::Handle1() {
  std::cout << "ConcreteStateA handles Request1." << '\n';
  std::cout << "ConcreteStateA wants to change the state of the context." << '\n';
  if (auto this_context = this->context_.lock()) {
    this_context->TransitionTo(std::make_unique<ConcreteStateB>());
  } else {
    std::cout << "Error: " << typeid(this->context_).name() << " expired in " << __func__ << '\n';
  }
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
  if (auto this_context = this->context_.lock()) {
    this_context->TransitionTo(std::make_shared<ConcreteStateA>());
  } else {
    std::cout << "Error: " << typeid(this->context_).name() << " expired in " << __func__ << '\n';
  }
}
