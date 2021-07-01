#ifndef TARGET_HPP_
#define TARGET_HPP_

#include <string>


// The Target defines the domain-specific interface used by the client code.
class Target {
public:
  virtual ~Target() = default;

  virtual std::string Request() const {
    return "Target: The default target's behavior.";
  }
};


#endif /* end of include guard: TARGET_HPP_ */
