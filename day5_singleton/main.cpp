#include <iostream>

#include "factory.hpp"
#include "product.hpp"

int main(int argc, char const *argv[]) {
  Product* cola = SingletonFactory::GetColaFactory().GetProduct();
  std::cout << cola->GetName() << '\n';
  Product* hamburger = SingletonFactory::GetHamburgerFactory().GetProduct();
  std::cout << hamburger->GetName() << '\n';

  // get the same instance every time
  std::cout << &(SingletonFactory::GetColaFactory()) << '\n';
  std::cout << &(SingletonFactory::GetColaFactory()) << '\n';

  std::cout << &(SingletonFactory::GetHamburgerFactory()) << '\n';
  std::cout << &(SingletonFactory::GetHamburgerFactory()) << '\n';

  return 0;
}
