#ifndef STATE_HPP_
#define STATE_HPP_

#include "context.hpp"

class Context;

// The base State class declares methods that all Concrete State should
// implement and also provides a backreference to the Context object, associated
// with the State. This backreference can be used by States to transition the
// Context to another State.
class State {
public:
  void SetContext(Context* const context);

  virtual void Handle1() = 0;
  virtual void Handle2() = 0;

  virtual ~State() = default;

protected:
  Context* context_;
};

// Concrete States implement various behaviors, associated with a state of the
// Context.
class ConcreteStateA : public State {
public:
  void Handle1() override;
  void Handle2() override;
};


class ConcreteStateB : public State {
public:
  void Handle1() override;
  void Handle2() override;
};


#endif /* end of include guard: STATE_HPP_ */
