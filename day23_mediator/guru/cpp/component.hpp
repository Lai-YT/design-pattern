#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_


class Mediator;


// The Base Component provides the basic functionality of storing a mediator's
// instance inside component objects.
class BaseComponent {
public:
  void SetMediator(Mediator* const mediator);

  BaseComponent(Mediator* const mediator = nullptr);
  virtual ~BaseComponent() = default;

protected:
  Mediator* mediator_;
};


// Concrete Components implement various functionality. They don't depend on
// other components. They also don't depend on any concrete mediator classes.
class Component1 : public BaseComponent {
public:
  void DoA() const;
  void DoB() const;
};

class Component2 : public BaseComponent {
public:
  void DoC() const;
  void DoD() const;
};


#endif /* end of include guard: COMPONENT_HPP_ */
