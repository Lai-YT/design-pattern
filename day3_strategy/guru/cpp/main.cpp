#include <iostream>

#include "context.hpp"
#include "strategy.hpp"

// The client code picks a concrete strategy and passes it to the context. The
// client should be aware of the differences between strategies in order to make
// the right choice.
void ClientCode() {
  Context context(new ConcreteStrategyA());
  std::cout << "Client: Strategy is set to normal sorting." << '\n';
  context.DoSomeBusinessLogic();
  std::cout << '\n';

  context.SetStrategy(new ConcreteStrategyB());
  std::cout << "Client: Strategy is set to reverse sorting." << '\n';
  context.DoSomeBusinessLogic();
}


int main(int argc, char const *argv[]) {
  ClientCode();
  // Client: Strategy is set to normal sorting.
  // Context: Sorting data using the strategy... (not sure how it'll do it)
  // Result: abcde
  //
  // Client: Strategy is set to reverse sorting.
  // Context: Sorting data using the strategy... (not sure how it'll do it)
  // Result: edcba
  
  return 0;
}
