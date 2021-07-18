#ifndef MEMENTO_HPP_
#define MEMENTO_HPP_

#include <ctime>
#include <string>

// The Memento interface provides a way to retrieve the memento's metadata, such
// as creation date or name. However, it doesn't expose the Originator's state.
class Memento {
public:
  virtual std::string name() const = 0;
  virtual std::string date() const = 0;

private:
  // Only Originators are allowed to access the state of Mementos.
  friend class Originator;
  virtual std::string state() const = 0;
};

// The Memento interface provides a way to retrieve the memento's metadata, such
// as creation date or name. However, it doesn't expose the Originator's state.
class ConcreteMemento : public Memento {
public:
  // The rest of the methods are used by the Caretaker to display metadata.
  std::string name() const override {
    return date_ + " / (" + state_.substr(0, 9) + "...)";
  }

  std::string date() const override {
    return state_;
  }

  ConcreteMemento(const std::string& state) {
    state_ = state;
    std::time_t now = std::time(0);
    date_ = std::ctime(&now);
  }

private:
  // The Originator uses this method when restoring its state.
  std::string state() const override {
    return state_;
  }

  std::string state_;
  std::string date_;
};


#endif /* end of include guard: MEMENTO_HPP_ */
