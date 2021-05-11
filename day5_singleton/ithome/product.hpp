#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include <string>

class Product {
public:
  Product() = default;
  virtual ~Product() = default;
  virtual std::string GetName() const = 0;
};

class Cola : public Product {
public:
  Cola() = default;
  virtual ~Cola() = default;
  std::string GetName() const override {
    return "cola";
  }
};

class Hamburger : public Product {
public:
  Hamburger() = default;
  virtual ~Hamburger() = default;
  std::string GetName() const override {
    return "hamburger";
  }
};

#endif /* end of include guard: PRODUCT_HPP_ */
