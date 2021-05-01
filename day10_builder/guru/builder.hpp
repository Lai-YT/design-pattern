#ifndef BUILDER_HPP_
#define BUILDER_HPP_

#include <iostream>
#include <memory>
#include <utility>

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
    this->Reset();
  }

  ~ConcreteBuilder() = default;

  void Reset() {
    std::cout << "Builder: Ready for a new build." << '\n';
    product_ = std::make_unique<Product>();
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

  std::unique_ptr<Product> GetProduct() {
    auto ready_product = std::move(product_);
    this->Reset();
    return ready_product;
  }

private:
  std::unique_ptr<Product> product_;
};

#endif /* end of include guard: BUILDER_HPP_ */
