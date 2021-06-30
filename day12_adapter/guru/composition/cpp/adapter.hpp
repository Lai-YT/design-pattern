#ifndef ADAPTER_HPP_
#define ADAPTER_HPP_

#include <algorithm>
#include <string>

#include "adaptee.hpp"
#include "target.hpp"


// The Adapter makes the Adaptee's interface compatible with the Target's
// interface.
class Adapter : public Target {
public:
  Adapter(Adaptee* adaptee)
    :adaptee_(adaptee) {}

  std::string Request() const override {
    std::string to_reverse = adaptee_->SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (TRANSLATED) " + to_reverse;
  }

private:
  Adaptee* adaptee_;
};


#endif /* end of include guard: ADAPTER_HPP_ */
