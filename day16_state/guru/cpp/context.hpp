#ifndef CONTEXT_HPP_
#define CONTEXT_HPP_

#include "state.hpp"

// The Context defines the interface of interest to clients. It also maintains a
// reference to an instance of a State subclass, which represents the current
// state of the Context.
class Context {
public:
  // The Context allows changing the State object at runtime.
  void TransitionTo(State* const state);

  // The Context delegates part of its behavior to the current State object.
  void Request1();
  void Request2();

  Context(State* state);
  ~Context();

private:
  // A reference to the current state of the Context.
  State* state_ = nullptr;
};


#endif /* end of include guard: CONTEXT_HPP_ */
