#include <memory>
#include <iostream>

#include "item.hpp"
#include "order.hpp"
#include "set.hpp"

int main(int argc, char const *argv[]) {
  std::cout << "Customization:" << '\n';

  auto soup = std::make_shared<Soup>();

  auto salad = std::make_shared<Salad>();
  salad->Decorate(soup);

  auto main_meal = std::make_shared<MainMeal>();
  main_meal->Decorate(salad);

  auto drink = std::make_shared<Drink>();
  drink->Decorate(main_meal);

  drink->Show();

  std::cout << "\nSets:" << '\n';

  SimpleSet simple_set;
  simple_set.Show();

  return 0;
}
