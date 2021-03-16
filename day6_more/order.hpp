#ifndef ORDER_HPP_
#define ORDER_HPP_

#include <vector>

#include "drink.hpp"
#include "strategy.hpp"

class DrinkOrder {
public:
  DrinkOrder() = default;
  ~DrinkOrder() {
      for (Drink* d : drink_list_) {
        delete d;
      }
  }

  void AddDrink(Drink* drink) {
    drink_list_.push_back(drink);
  }

  double GetTotalPrice(IDiscountStrategy* discount_strategy) {
    double total_price = TotalPrice();
    total_price = discount_strategy->GetValue(total_price);
    delete discount_strategy;
    return total_price;
  }

private:
  std::vector<Drink*> drink_list_;

  double TotalPrice() {
    double total_price = 0;
    for (Drink* d : drink_list_) {
      total_price += d->GetValue();
    }
    return total_price;
  }
};

#endif /* end of include guard: ORDER_HPP_ */
