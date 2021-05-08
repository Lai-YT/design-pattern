#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_

class IStrategy {
public:
  IStrategy() = default;
  virtual ~IStrategy() = default;
  virtual int Calculate(int, int) = 0;
};

class Add : public IStrategy {
  int Calculate(int a, int b) override {
    return a + b;
  }
};

class Minus : public IStrategy {
  int Calculate(int a, int b) override {
    return a - b;
  }
};

class Multiply : public IStrategy {
  int Calculate(int a, int b) override {
    return a * b;
  }
};

class Divide : public IStrategy {
  int Calculate(int a, int b) override {
    return a / b;
  }
};

#endif /* end of include guard: STRATEGY_HPP_ */
