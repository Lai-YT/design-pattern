#ifndef DIRECTOR_HPP_
#define DIRECTOR_HPP_

#include <iostream>
#include <memory>
#include <utility>

#include "builder.hpp"

// The Director is only responsible for executing the building
// steps in a particular sequence.
class Director {
public:
  Director() = default;

  ~Director() = default;

  void SetBuilder(std::shared_ptr<Builder> builder) {
    builder_ = builder;
  }

  // The Director can construct several product variations
  // using the same building steps.
  void BuildMinimalViableProduct() const {
    std::cout << "Director: Building basic product..." << '\n';
    builder_->ProducePartA();
    std::cout << "Done." << '\n';
  }

  void BuildFullFeaturedProduct() const {
    std::cout << "Director: Building full featured product..." << '\n';
    builder_->ProducePartA();
    builder_->ProducePartB();
    builder_->ProducePartC();
    std::cout << "Done." << '\n';
  }

private:
  std::shared_ptr<Builder> builder_ = nullptr;
};

#endif /* end of include guard: DIRECTOR_HPP_ */
