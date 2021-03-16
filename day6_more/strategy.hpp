#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_

class IDiscountStrategy {
public:
  IDiscountStrategy() = delete;
  IDiscountStrategy(double discount)
    :discount_(discount)
  {}
  virtual ~IDiscountStrategy() = default;
  virtual double GetValue(double value) const = 0;
protected:
  double discount_;
};

class MinusDiscount : public IDiscountStrategy {
public:
  MinusDiscount() = delete;
  MinusDiscount(double discount)
    :IDiscountStrategy(discount)
  {}
  virtual ~MinusDiscount() = default;

  double GetValue(double value) const override {
    return value - discount_;
  }
};

class MultiplyStrategy : public IDiscountStrategy {
public:
  MultiplyStrategy() = delete;
  MultiplyStrategy(double discount)
    :IDiscountStrategy(discount)
  {}
  virtual ~MultiplyStrategy() = default;

  double GetValue(double value) const override {
    return value * discount_;
  }
};

class NoneDiscount : public IDiscountStrategy {
public:
  NoneDiscount()
    :IDiscountStrategy(0)
  {}
  virtual ~NoneDiscount() = default;

  double GetValue(double value) const override {
    return value;
  }
};

#endif /* end of include guard: STRATEGY_HPP_ */
