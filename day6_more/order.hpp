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
    total_price_ += drink->GetValue();
  }

  double GetTotalPrice(IDiscountStrategy* discount_strategy) {
    double total_price = discount_strategy->GetValue(total_price_);
    delete discount_strategy;   // strategy is disposable
    
    return total_price;
  }

private:
  std::vector<Drink*> drink_list_;
  double total_price_ = 0;

};

#endif /* end of include guard: ORDER_HPP_ */
