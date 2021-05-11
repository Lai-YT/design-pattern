#ifndef DRINK_HPP_
#define DRINK_HPP_

#include <iostream>
#include <string>

// -----base class: Drink-----

enum class SugarType {
  kRegular, kLess, kHalf, lQuarter, kFree
};

enum class IceType {
  kRegular, kEasy, kFree, kHot
};

class Drink {
public:
  Drink() = delete;
  Drink(SugarType sugar_type, IceType ice_type)
    :sugar_type_(sugar_type)
    ,ice_type_(ice_type)
  {}

  virtual ~Drink() = default;

  SugarType GetSugar() const {
    return sugar_type_;
  }

  IceType GetIce() const {
    return ice_type_;
  }

  virtual void Describe() = 0;

private:
  SugarType sugar_type_;
  IceType ice_type_;
};

// -----derived class: Tea-----

enum class TeaType {
  kkBlack, kGreen, kOolong
};

class Tea : public Drink {
public:
  Tea() = delete;
  Tea(SugarType sugar_type, IceType ice_type)
    :Drink(sugar_type, ice_type)
  {}

  TeaType GetTeaType() const {
    return tea_type_;
  }

  void SetTeaType(TeaType tea_type) {
    tea_type_ = tea_type;
  }

  void Describe() override {
    std::cout << "It's a cup of tea" << '\n';
  }

private:
  TeaType tea_type_;
};

// -----derived class: Coffee-----

enum class CoffeeType {
  kLatte, kAmericano, kEspresso
};

class Coffee : public Drink {
public:
  Coffee() = delete;
  Coffee(SugarType sugar_type, IceType ice_type)
    :Drink(sugar_type, ice_type)
  {}


  CoffeeType GetCoffeeType() const {
    return coffee_type_;
  }

  void SetCoffeeType(CoffeeType coffee_type) {
    coffee_type_ = coffee_type;
  }

  void Describe() override {
    std::cout << "It's a cup of coffee" << '\n';
  }

private:
  CoffeeType coffee_type_;
};

#endif /* end of include guard: DRINK_HPP_ */
