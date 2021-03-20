#include "item.hpp"
#include "order.hpp"

int main(int argc, char const *argv[]) {

  Drink* drink = new Drink();
  MainMeal* main_meal = new MainMeal();
  Soup* soup = new Soup();

  main_meal->Decorate(drink);
  soup->Decorate(main_meal);

  soup->Show();

  delete drink;
  delete main_meal;
  delete soup;

  return 0;
}
