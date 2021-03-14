#include <iostream>

#include "calculator.hpp"
#include "strategy.hpp"

int main(int argc, char const *argv[]) {

  Calculator calculator;

  calculator.SetStrategy(DoType::kAdd);
  std::cout << "5 + 9 = " << calculator.Execute(5, 9) << '\n';

  calculator.SetStrategy(DoType::kMinus);
  std::cout << "5 - 9 = " << calculator.Execute(5, 9) << '\n';

  calculator.SetStrategy(DoType::kMultyply);
  std::cout << "5 * 9 = " << calculator.Execute(5, 9) << '\n';

  calculator.SetStrategy(DoType::kDivide);
  std::cout << "5 / 9 = " << calculator.Execute(5, 9) << '\n';

  return 0;
}
