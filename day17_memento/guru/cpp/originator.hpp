#ifndef ORIGINATOR_HPP_
#define ORIGINATOR_HPP_

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

#include "memento.hpp"

// The Originator holds some important state that may change over time. It also
// defines a method for saving the state inside a memento and another method for
// restoring the state from it.
class Originator {
public:
  // The Originator's business logic may affect its internal state. Therefore,
  // the client should backup the state before launching methods of the business
  // logic via the save() method.
  void DoSomething() {
    std::cout << "Originator: I'm doing something important." << '\n';
    state_ = GenerateRandomString(30);
    std::cout << "Originator: And my state has changed to " << state_ << ".\n";
  }

  // Saves the current state inside a memento.
  std::unique_ptr<Memento> Save() const {
    return std::make_unique<ConcreteMemento>(state_);
  }

  // Restores the Originator's state from a memento object.
  void Restore(const std::unique_ptr<Memento>& memento) {
    state_ = memento->state();
    std::cout << "Originator: My state has changed to: " << state_ << ".\n";
  }

  Originator(const std::string& state)
    :state_(state) {
    std::cout << "Originator: My initial state is " << state_ << '\n';
  }

private:
  std::string GenerateRandomString(const int length = 10) {
    std::string alphanum = "0123456789"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                            "abcdefghijklmnopqrstuvwxyz";
    std::string random_string = "";
    for (size_t i = 0; i < length; i++) {
      random_string += alphanum.at(std::rand() % alphanum.length());
    }
    return random_string;
  }

  // For the sake of simplicity, the originator's state is stored
  // inside a single variable.
  std::string state_;
};


#endif /* end of include guard: ORIGINATOR_HPP_ */
