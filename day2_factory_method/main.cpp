#include "factory.hpp"
#include "product.hpp"

// always get products from the factory

int main(int argc, char const *argv[]) {

  Factory* fries_fac = new FrenchFriesFactory();
  Product* fries = fries_fac->GetProduct();
  Product* my_fries = dynamic_cast<FrenchFriesFactory*>(fries_fac)->GetProduct("no salt");

  fries->Describe();
  my_fries->Describe();

  delete fries_fac;
  delete fries;
  delete my_fries;

  return 0;
}
