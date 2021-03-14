#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include <iostream>
#include <string>

class Product {
public:
  virtual void Describe() = 0;
};

class FrenchFries : public Product {
public:
  FrenchFries(std::string state = "salt")
    :state_(state) {}

  void Describe() override {
    std::cout << "I'm " + state_ + " french fries" << '\n';
  }
private:
  std::string state_;
};

#endif /* end of include guard: PRODUCT_HPP_ */
