#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <string>

#include "product.hpp"

class Factory {
public:
  Factory() = default;
  virtual ~Factory() = default;
  virtual Product* GetProduct() = 0;
};

class FrenchFriesFactory : public Factory {
public:
  FrenchFriesFactory() = default;
  virtual ~FrenchFriesFactory() = default;
  
  Product* GetProduct() override {
    return new FrenchFries();
  }

  Product* GetProduct(std::string state) {
    return new FrenchFries(state);
  }
};

#endif /* end of include guard: FACTORY_HPP_ */
