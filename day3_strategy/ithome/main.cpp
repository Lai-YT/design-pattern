#include <iostream>

#include "calculator.hpp"
#include "strategy.hpp"

// just add a new strategy if having a new calculation,
// and still calling function from the Calculator

int main(int argc, char const *argv[]) {

  Calculator calculator;

  calculator.SetStrategy(EnumDo::Add);
  std::cout << "5 + 9 = " << calculator.Execute(5, 9) << '\n';

  calculator.SetStrategy(EnumDo::Minus);
  std::cout << "5 - 9 = " << calculator.Execute(5, 9) << '\n';

  calculator.SetStrategy(EnumDo::Multiply);
  std::cout << "5 * 9 = " << calculator.Execute(5, 9) << '\n';

  calculator.SetStrategy(EnumDo::Divide);
  std::cout << "5 / 9 = " << calculator.Execute(5, 9) << '\n';

  return 0;
}
