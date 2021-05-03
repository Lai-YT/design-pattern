#ifndef CREATOR_HPP_
#define CREATOR_HPP_

#include <string>

#include "product.hpp"

// The Creator class declares the factory method that is supposed to return an
// object of a Product class. The Creator's subclasses usually provide the
// implementation of this method.
class Creator {
public:
  virtual ~Creator() = default;
  virtual Product* FactoryMethod() const = 0;

  // Note that the Creator may also provide some default implementation of the
  // factory method.
  std::string SomeOperation() const {
    // Call the factory method to create a Product object.
    Product* product = this->FactoryMethod();
    // Now, use the product.
    std::string result = "Creator: The same creator's code has just worked with "
                         + product->Operation();
    delete product;
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
  ConcreteProduct1* FactoryMethod() const override {
    return new ConcreteProduct1();
  }
};

class ConcreteCreator2 : public Creator {
public:
  ConcreteProduct2* FactoryMethod() const override {
    return new ConcreteProduct2();
  }
};

#endif /* end of include guard: CREATOR_HPP_ */
