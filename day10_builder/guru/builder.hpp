#ifndef BUILDER_HPP_
#define BUILDER_HPP_

#include <iostream>

#include "product.hpp"

// The Builder interface specifies methods for creating the different parts of
// the Product objects.
class Builder {
public:
  virtual ~Builder() = default;
  virtual void ProducePartA() const = 0;
  virtual void ProducePartB() const = 0;
  virtual void ProducePartC() const = 0;
};

class ConcreteBuilder : public Builder {
public:
  // A fresh builder instance should contain a blank product object, which is
  // used in further assembly.
  ConcreteBuilder() {
    this->_Reset();
  }

  ~ConcreteBuilder() {
    delete product_;
  }

  // All production steps work with the same product instance.
  void ProducePartA() const override {
    product_->AddPart("PartA");
  }

  void ProducePartB() const override {
    product_->AddPart("PartB");
  }

  void ProducePartC() const override {
    product_->AddPart("PartC");
  }

  // The user of this function is responsible to release the memory.
  Product* GetProduct() {
    Product* ready_product = product_;
    this->_Reset();
    return ready_product;
  }

private:
  Product* product_;

  // Calling Reset individually causes memory leak,
  // so make it private.
  void _Reset() {
    std::cout << "Builder: Ready for a new build." << '\n';
    product_ = new Product();
  }
};

#endif /* end of include guard: BUILDER_HPP_ */
