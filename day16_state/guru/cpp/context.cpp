#include <iostream>
#include <memory>
#include <typeinfo>

#include "context.hpp"
#include "state.hpp"


// weak_from_this is used instead of shared_from_this to break circular reference.
void Context::TransitionTo(std::shared_ptr<State> state) {
  // +2 on the name is just a manipulation on c-string for this specific case to remove prefix.
  std::cout << "Context: Transition to " << typeid(*state).name() + 2 << ".\n";
  this->state_ = state;
  this->state_->SetContext(weak_from_this());
}

void Context::Request1() {
  this->state_->Handle1();
}

void Context::Request2() {
  this->state_->Handle2();
}

std::shared_ptr<Context> Context::CreateSharedWithInitState(std::shared_ptr<State> state) {
  auto context = std::make_shared<Context>();
  context->TransitionTo(state);
  return context;
}
