#ifndef CACULATOR_HPP_
#define CACULATOR_HPP_

#include "strategy.hpp"

enum class DoType {
  kAdd, kMinus, kDivide, kMultyply
};

class Calculator {
public:

  Calculator() = default;

  ~Calculator() {
    if (strategy_) {
      delete strategy_;
    }
  }

  // strategy pattern
  int Execute(int a, int b) {
    return strategy_->Calculate(a, b);
  }

  // simple factory pattern
  void SetStrategy(DoType type) {
    switch (type) {
      case DoType::kAdd:
        strategy_ = new Add();
        break;
      case DoType::kMinus:
        strategy_ = new Minus();
        break;
      case DoType::kMultyply:
        strategy_ = new Multyply();
        break;
      case DoType::kDivide:
        strategy_ = new Divide();
        break;
    }
  }
private:
  IStrategy* strategy_;
};

#endif /* end of include guard: CACULATOR_HPP_ */
