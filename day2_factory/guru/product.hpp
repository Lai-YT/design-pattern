#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include <string>

// The Product interface declares the operations that all concrete products must
// implement.
class Product {
public:
  virtual ~Product() = default;
  virtual std::string Operation() const = 0;
};

// Concrete Products provide various implementations of the Product interface.
class ConcreteProduct1 : public Product {
public:
  std::string Operation() const override {
    return "(Result of the ConcreteProduct1)";
  }
};


class ConcreteProduct2 : public Product {
public:
  std::string Operation() const override {
    return "(Result of the ConcreteProduct2)";
  }
};

#endif /* end of include guard: PRODUCT_HPP_ */
