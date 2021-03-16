#ifndef DRINK_HPP_
#define DRINK_HPP_

#include "strategy.hpp"

class Drink {
public:
  Drink() = delete;
  Drink(double value, IDiscountStrategy* discount_strategy)
    :value_(value),discount_strategy_(discount_strategy)
  {}
  virtual ~Drink() {
    delete discount_strategy_;
  }

  double GetValue() const {
    return discount_strategy_->GetValue(value_);
  }

private:
  IDiscountStrategy* discount_strategy_;
  double value_;
};

class MilkTea : public Drink {
public:
  MilkTea() = delete;
  MilkTea(double value, IDiscountStrategy* discount_strategy = new NoneDiscount())
    :Drink(value, discount_strategy)
  {}
  virtual ~MilkTea() = default;
};

class Coffee : public Drink {
public:
  Coffee() = delete;
  Coffee(double value, IDiscountStrategy* discount_strategy = new NoneDiscount())
    :Drink(value, discount_strategy)
  {}
  virtual ~Coffee() = default;
};

#endif /* end of include guard: DRINK_HPP_ */
