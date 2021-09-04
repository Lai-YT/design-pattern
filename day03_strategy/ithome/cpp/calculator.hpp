#ifndef CACULATOR_HPP_
#define CACULATOR_HPP_

#include "strategy.hpp"

enum class EnumDo {
  Add, Minus, Divide, Multiply
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
  void SetStrategy(EnumDo do_type) {
    switch (do_type) {
      case EnumDo::Add:
        strategy_ = new Add();
        break;
      case EnumDo::Minus:
        strategy_ = new Minus();
        break;
      case EnumDo::Multiply:
        strategy_ = new Multiply();
        break;
      case EnumDo::Divide:
        strategy_ = new Divide();
        break;
      default:
        strategy_ = nullptr;
        break;
    }
  }
private:
  IStrategy* strategy_ = nullptr;
};

#endif /* end of include guard: CACULATOR_HPP_ */
