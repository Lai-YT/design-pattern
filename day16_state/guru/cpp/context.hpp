#ifndef CONTEXT_HPP_
#define CONTEXT_HPP_

#include <memory>

#include "state.hpp"

// The Context defines the interface of interest to clients. It also maintains a
// reference to an instance of a State subclass, which represents the current
// state of the Context.
class Context : public std::enable_shared_from_this<Context> {
public:
  // The Context allows changing the State object at runtime.
  void TransitionTo(std::shared_ptr<State> state);

  // The Context delegates part of its behavior to the current State object.
  void Request1();
  void Request2();

  // weak_from_this will be called to set States, which doesn't work inside a
  // construtor since the object itself hasn't finished the constrution yet.
  // So this static creation method is used instead as an alternative constructor
  // and the default construtor is deleted to avoid construtions of State-uninitialized Contexts.
  static std::shared_ptr<Context> CreateSharedWithInitState(std::shared_ptr<State> state);

  // Be careful when you construt a State-uninitialized Contexts.
  // One should call TransitionTo() right after it.
  Context() = default;

private:
  // A reference to the current state of the Context.
  std::shared_ptr<State> state_;
};


#endif /* end of include guard: CONTEXT_HPP_ */
