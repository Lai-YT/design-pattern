#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "product.hpp"

class Factory {
public:
  Factory() = default;
  virtual ~Factory() = default;
  virtual Product* GetProduct() = 0;
};

class SingletonFactory {
  class ColaFactory;
  class HamburgerFactory;
public:
  SingletonFactory() = default;
  virtual ~SingletonFactory() = default;

  static ColaFactory& GetColaFactory() {
    static ColaFactory cola_factory;
    return cola_factory;
  }

  static HamburgerFactory& GetHamburgerFactory() {
    static HamburgerFactory hamburger_factory;
    return hamburger_factory;
  }

// put inner class in private, so can't be observed from the outside 
private:
  class ColaFactory : public Factory {
  public:
    ColaFactory() = default;
    virtual ~ColaFactory() = default;

    Product* GetProduct() override {
      return new Cola();
    }
  };

  class HamburgerFactory : public Factory {
  public:
    HamburgerFactory() = default;
    virtual ~HamburgerFactory() = default;

    Product* GetProduct() override {
      return new Hamburger();
    }
  };

};

#endif /* end of include guard: FACTORY_HPP_ */
