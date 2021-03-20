#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <iostream>

#include "order.hpp"

class Item : public Order {
public:
  Item() = default;
  virtual ~Item() = default;

  void Decorate(Order* order) {
    order_ = order;
  }
  void Show() const override {
    if (order_) {
      order_->Show();
    }
  }
protected:
  Order* order_ = nullptr;
};

class Drink : public Item {
public:
  Drink(): Item() {}
  virtual ~Drink() = default;

  void Show() const override {
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

  void Show() const override {
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

  void Show() const override {
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

  void Show() const override {
    Item::Show();
    AddMainMeal();
  }
private:
  void AddMainMeal() const {
    std::cout << "add main meal " << '\n';
  }
};

#endif /* end of include guard: ITEM_HPP_ */
