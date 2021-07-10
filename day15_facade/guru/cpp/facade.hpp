#ifndef FACADE_HPP_
#define FACADE_HPP_

#include <memory>
#include <string>
#include <utility>  // std::move

#include "subsystem.hpp"

// The Facade class provides a simple interface to the complex logic of one or
// several subsystems. The Facade delegates the client requests to the
// appropriate objects within the subsystem. The Facade is also responsible for
// managing their lifecycle. All of this shields the client from the undesired
// complexity of the subsystem.
class Facade {
public:
  // The Facade's methods are convenient shortcuts to the sophisticated
  // functionality of the subsystems. However, clients get only to a fraction of
  // a subsystem's capabilities.
  std::string Operation() const {
    std::string result = "Facade initializes subsystems.\n";
    result += subsystem1_->Operation1();
    result += subsystem2_->Operation1();
    result += "Facade orders subsystems to perform the action.\n";
    result += subsystem1_->OperationN();
    result += subsystem2_->OperationZ();
    return result;
  }

  // Depending on your application's needs, you can provide the Facade with
  // existing subsystem objects or force the Facade to create them on its own.
  // In this case we will delegate the memory ownership to Facade Class.
  Facade(std::unique_ptr<Subsystem1>&& subsystem1 = nullptr,
         std::unique_ptr<Subsystem2>&& subsystem2 = nullptr)
    :subsystem1_(std::move(subsystem1)),subsystem2_(std::move(subsystem2)) {
    // Omit the second operand means that if the condition is true,
    // return the value which the condition itself implies.
    subsystem1_ ?: subsystem1_ = std::make_unique<Subsystem1>();
    subsystem2_ ?: subsystem2_ = std::make_unique<Subsystem2>();
    // Same as "if(!subsystem_) subsystem_ = std::make_unique<Subsystem>();".
  }

private:
  std::unique_ptr<Subsystem1> subsystem1_;
  std::unique_ptr<Subsystem2> subsystem2_;

};


#endif /* end of include guard: FACADE_HPP_ */
