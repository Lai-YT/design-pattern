#include "client.hpp"
#include "drink.hpp"

// having various kinds of drinks, sugar types, ice types, ... ,
// can get combinations from the client, make 1 + 1 > 2

int main(int argc, char const *argv[]) {
  Client client;

  Drink* tea = client.order("Tea", SugarType::kFree, IceType::kEasy);
  dynamic_cast<Tea*>(tea)->SetTeaType(TeaType::kOolong);

  tea->Describe();

  Drink* coffee = client.order("Coffee", SugarType::kFree, IceType::kHot);
  dynamic_cast<Coffee*>(coffee)->SetCoffeeType(CoffeeType::kAmericano);

  coffee->Describe();

  delete tea;
  delete coffee;

  return 0;
}
