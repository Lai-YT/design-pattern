#ifndef CONTEXT_HPP_
#define CONTEXT_HPP_

#include <memory>
#include <utility>

#include "strategy.hpp"


// The Context defines the interface of interest to clients.
class Context {
public:
  // Usually, the Context allows replacing a Strategy object at runtime.
  void SetStrategy(std::unique_ptr<Strategy> strategy) {
    strategy_ = std::move(strategy);
  }

  // The Context delegates some work to the Strategy object instead of
  // implementing +multiple versions of the algorithm on its own.
  void DoSomeBusinessLogic() const {
    std::cout << "Context: Sorting data using the strategy... (not sure how it'll do it)" << '\n';
    const std::string result = strategy_->DoAlgorithm(std::vector<std::string>{"a", "e", "c", "b", "d"});
    std::cout << "Result: " << result << '\n';
  }

  // Usually, the Context accepts a strategy through the constructor, but also
  // provides a setter to change it at runtime.
  Context(std::unique_ptr<Strategy> strategy)
      : strategy_(std::move(strategy)) {}

private:
  // The Context maintains a reference to one of the Strategy
  // objects. The Context does not know the concrete class of a strategy. It
  // should work with all strategies via the Strategy interface.
  std::unique_ptr<Strategy> strategy_;
};


#endif /* end of include guard: CONTEXT_HPP_ */
