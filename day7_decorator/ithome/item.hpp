#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <iostream>
#include <memory>

#include "order.hpp"

// Items are components, but they can also decorate themselves.
class Item : public Order {
public:
  virtual ~Item() = default;

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


class Drink : public Item {
public:
  Drink() = default;
  virtual ~Drink() = default;

  void Show() override {
    Item::Show();
    AddDrink();
  }

private:
  void AddDrink() const {
    std::cout << "--> drink" << '\n';
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
    std::cout << "--> salad" << '\n';
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
    std::cout << "--> soup" << '\n';
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
    std::cout << "--> main meal " << '\n';
  }
};


#endif /* end of include guard: ITEM_HPP_ */
