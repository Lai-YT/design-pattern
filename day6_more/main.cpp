#include <iostream>

#include "drink.hpp"
#include "order.hpp"
#include "strategy.hpp"

int main(int argc, char const *argv[]) {
  DrinkOrder drink_order;

  drink_order.AddDrink(new Coffee(165));
  // individual discount
  drink_order.AddDrink(new MilkTea(55, new MinusDiscount(20)));
  // order list discount
  double price = drink_order.GetTotalPrice(new NoneDiscount);
  std::cout << price << '\n';
  price = drink_order.GetTotalPrice(new MultiplyStrategy(0.9));
  std::cout << price << '\n';

  return 0;
}
