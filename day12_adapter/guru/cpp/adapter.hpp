#ifndef ADAPTER_HPP_
#define ADAPTER_HPP_

#include <algorithm>
#include <string>

#include "adaptee.hpp"
#include "target.hpp"


// this is so-called the Object Adapter Pattern
namespace composition {
  // The Adapter makes the Adaptee's interface compatible with the Target's
  // interface.
  class Adapter : public Target {
  public:
    Adapter(Adaptee* adaptee)
      :adaptee_(adaptee) {}

    std::string Request() const override {
      std::string to_reverse = adaptee_->SpecificRequest();
      std::reverse(to_reverse.begin(), to_reverse.end());
      return "Composition Adapter: (TRANSLATED) " + to_reverse;
    }

  private:
    Adaptee* adaptee_;
  };

}  // namespace composition


// this is so-called the Class Adapter Pattern
namespace inheritance {
  // The Adapter makes the Adaptee's interface compatible with the Target's
  // interface using multiple inheritance.
  class Adapter : public Target, public Adaptee {
  public:
    Adapter() = default;

    std::string Request() const override {
      std::string to_reverse = this->SpecificRequest();
      std::reverse(to_reverse.begin(), to_reverse.end());
      return "Inheritance Adapter: (TRANSLATED) " + to_reverse;
    }
  };

}  // namespace inheritance


#endif /* end of include guard: ADAPTER_HPP_ */
