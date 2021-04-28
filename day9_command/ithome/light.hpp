#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include <iostream>

// Light is the receiver
class Light {
public:
  void TurnOn() const {
    std::cout << "Light is turned on" << '\n';
  }

  void TurnOff() const {
    std::cout << "Light is turned off" << '\n';
  }

  void Brighten() const {
    std::cout << "Light is brightened" << '\n';
  }

  void Darken() const {
    std::cout << "Light is darkened" << '\n';
  }
};

#endif /* end of include guard: LIGHT_HPP_ */
