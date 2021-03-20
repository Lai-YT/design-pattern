#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <iostream>

#include "order.hpp"

class Item : public Order {
public:
  Item() = default;
  virtual ~Item() {
    delete order_;
  };

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

class Drink : public Item {
public:
  Drink(): Item() {}
  virtual ~Drink() = default;

  void Show() override {
    Item::Show();
    AddDrink();
  }
private:
  void AddDrink() const {
    std::cout << "add a cup of drink" << '\n';
  }
};

class Salad : public Item {
public:
  Salad() = default;
  virtual ~Salad() = default;

  void Show() override {
    Item::Show();
    AddSalad();
  }
private:
  void AddSalad() const {
    std::cout << "add a plate of salad" << '\n';
  }
};

class Soup : public Item {
public:
  Soup() = default;
  virtual ~Soup() = default;

  void Show() override {
    Item::Show();
    AddSoup();
  }
private:
  void AddSoup() const {
    std::cout << "add a bowl of soup" << '\n';
  }
};

class MainMeal : public Item {
public:
  MainMeal() = default;
  virtual ~MainMeal() = default;

  void Show() override {
    Item::Show();
    AddMainMeal();
  }
private:
  void AddMainMeal() const {
    std::cout << "add main meal " << '\n';
  }
};

// use LastOrder to wrap the last order,
// so make sure the destructors of all orders are chain-invoked

class LastOrder final : public Item {
public:
  LastOrder() = delete;
  LastOrder(Order* order):Item() {
    Item::Decorate(order);
  }
  ~LastOrder() = default;

  using Item::Show;

  // for safety, allocations in heap are forbidden
  void* operator new(size_t) = delete;
  void* operator new[](size_t) = delete;
};

#endif /* end of include guard: ITEM_HPP_ */
