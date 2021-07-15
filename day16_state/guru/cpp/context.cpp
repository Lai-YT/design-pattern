#include <iostream>
#include <typeinfo>

#include "context.hpp"
#include "state.hpp"


void Context::TransitionTo(State* const state) {
  std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
  if (this->state_) {
    delete this->state_;
  }
  this->state_ = state;
  this->state_->SetContext(this);
}

void Context::Request1() {
  this->state_->Handle1();
}

void Context::Request2() {
  this->state_->Handle2();
}

Context::Context(State* state) {
  this->TransitionTo(state);
}

Context::~Context() {
  delete this->state_;
}
