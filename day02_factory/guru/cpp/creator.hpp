#ifndef CREATOR_HPP_
#define CREATOR_HPP_

#include <memory>
#include <string>

#include "product.hpp"

// The Creator class declares the factory method that is supposed to return an
// object of a Product class. The Creator's subclasses usually provide the
// implementation of this method.
class Creator {
public:
  virtual ~Creator() = default;
  virtual std::unique_ptr<Product> FactoryMethod() const = 0;

  // Note that the Creator may also provide some default implementation of the
  // factory method.
  std::string SomeOperation() const {
    // Call the factory method to create a Product object.
    std::unique_ptr<Product> product = this->FactoryMethod();
    // Now, use the product.
    std::string result = "Creator: The same creator's code has just worked with "
                         + product->Operation();
    return result;
  }
};

// Concrete Creators override the factory method in order to change the
// resulting product's type.
class ConcreteCreator1 : public Creator {
public:
  // Note that the signature of the method still uses the abstract product type,
  // even though the concrete product is actually returned from the method. This
  // way the Creator can stay independent of concrete product classes.
  std::unique_ptr<Product> FactoryMethod() const override {
    return std::make_unique<ConcreteProduct1>();
  }
};

class ConcreteCreator2 : public Creator {
public:
  std::unique_ptr<Product> FactoryMethod() const override {
    return std::make_unique<ConcreteProduct2>();
  }
};

#endif /* end of include guard: CREATOR_HPP_ */
