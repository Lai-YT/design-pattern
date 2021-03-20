#ifndef SET_HPP_
#define SET_HPP_

#include "order.hpp"

class Set : public Order {
public:
  Set() = default;
  virtual ~Set() {
    delete order_;
  }

  void Decorate(Order* order) {
    order_ = order;
  }
  void Show() override {
    if (order_) {
      order_->Show();
    }
  }
private:
  Order* order_ = nullptr;
};

class SimpleSet : public Set {
public:
  SimpleSet() = default;
  virtual ~SimpleSet() = default;

  void Show() override {
    AddSet();
    Set::Show();
  }

private:
  void AddSet() {
    Salad* salad = new Salad();
    MainMeal* main_meal = new MainMeal();
    Drink* drink = new Drink();
    main_meal->Decorate(salad);
    drink->Decorate(main_meal);
    Set::Decorate(drink);
  }
};

#endif /* end of include guard: SET_HPP_ */
