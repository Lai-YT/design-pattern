#include <iostream>

#include "item.hpp"
#include "order.hpp"
#include "set.hpp"

int main(int argc, char const *argv[]) {

  Drink* drink = new Drink();
  MainMeal* main_meal = new MainMeal();
  main_meal->Decorate(drink);

  Salad* salad = new Salad();
  salad->Decorate(main_meal);

  Soup* soup = new Soup();
  soup->Decorate(salad);

  // 'LastOrder' handles all memory allocations,
  //  all destructors of related 'Order's are guaranteed to be called
  LastOrder last_order(soup);
  last_order.Show();
  
  std::cout << "---" << '\n';

  SimpleSet simple_set;
  simple_set.Show();

  return 0;
}
