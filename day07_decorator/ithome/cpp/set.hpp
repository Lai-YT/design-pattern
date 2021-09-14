#ifndef SET_HPP_
#define SET_HPP_

#include <memory>

#include "order.hpp"

// Sets are both components and decorators that decorate multiple Items
// inside automatically.
class Set : public Order {
public:
  virtual ~Set() = default;

  void Decorate(std::shared_ptr<Order> order) {
    order_ = order;
  }

  void Show() override {
    if (order_) {
      order_->Show();
    }
  }

private:
  std::shared_ptr<Order> order_ = nullptr;
};


class SimpleSet : public Set {
public:
  virtual ~SimpleSet() = default;

  void Show() override {
    AddSet();
    Set::Show();
  }

private:
  void AddSet() {
    auto salad = std::make_shared<Salad>();

    auto main_meal = std::make_shared<MainMeal>();
    main_meal->Decorate(salad);

    auto drink = std::make_shared<Drink>();
    drink->Decorate(main_meal);
    
    Set::Decorate(drink);
  }
};

#endif /* end of include guard: SET_HPP_ */
