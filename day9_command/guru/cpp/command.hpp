#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include <iostream>
#include <string>

#include "receiver.hpp"

// The Command interface declares a method for executing a command.
class Command {
public:
  virtual ~Command() = default;
  virtual void Execute() const = 0;
};

// Some commands can implement simple operations on their own.
class SimpleCommand : public Command {
public:
  explicit SimpleCommand(const std::string& pay_load)
    :pay_load_(pay_load) {}

  void Execute() const override {
    std::cout << "SimpleCommand: See, I can do simple things like printing ("
              << pay_load_ << ")\n";
  }

private:
  std::string pay_load_;
};

// However, some commands can delegate more complex operations to other objects,
// called "receivers."
class ComplexCommand : public Command {
public:

  // Complex commands can accept one or several receiver objects along with any
  // context data via the constructor.
  ComplexCommand(Receiver* receiver, const std::string& a, const std::string& b)
    :receiver_(receiver),a_(a),b_(b) {}

  // Commands can delegate to any methods of a receiver.
  void Execute() const override {
    std::cout << "ComplexCommand: Complex stuff should be done by a receiver object." << '\n';
    receiver_->DoSomething(a_);
    receiver_->DoSomethingElse(b_);
  }

private:
  Receiver *receiver_;

  // Context data, required for launching the receiver's methods.
  std::string a_;
  std::string b_;
};


#endif /* end of include guard: COMMAND_HPP_ */
