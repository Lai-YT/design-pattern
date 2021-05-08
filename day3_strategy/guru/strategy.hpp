#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

// The Strategy interface declares operations common to all supported versions
// of some algorithm.

// The Context uses this interface to call the algorithm defined by Concrete
// Strategies.
class Strategy {
public:
  virtual ~Strategy() = default;
  virtual std::string DoAlgorithm(const std::vector<std::string>& data) const = 0;
};

// Concrete Strategies implement the algorithm while following the base Strategy
// interface. The interface makes them interchangeable in the Context.
class ConcreteStrategyA : public Strategy {
public:
  std::string DoAlgorithm(const std::vector<std::string>& data) const override {
    std::string result = "";

    // put chars into std::string and do normal sorting
    for (auto letter : data) {
      result += letter;
    }
    std::sort(result.begin(), result.end());

    return result;
  }

};


class ConcreteStrategyB : public Strategy {
public:
  std::string DoAlgorithm(const std::vector<std::string>& data) const override {
    std::string result = "";

    // put chars into std::string and do reverse sorting
    for (auto letter : data) {
      result += letter;
    }
    std::sort(result.begin(), result.end(), std::greater<char>());

    return result;
  }

};

#endif /* end of include guard: STRATEGY_HPP_ */
