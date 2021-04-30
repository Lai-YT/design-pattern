// It makes sense to use the Builder pattern only when your products are quite
// complex and require extensive configuration.

#include "builder.hpp"
#include "director.hpp"
#include "product.hpp"

// The client code creates a builder object, passes it to the director and then
// initiates the construction process. The end result is retrieved from the
// builder object.
void ClientCode(Director& director) {
  ConcreteBuilder* builder = new ConcreteBuilder();
  director.SetBuilder(builder);

  // build product
  director.BuildMinimalViableProduct();

  // get product
  Product* min_product = builder->GetProduct();
  min_product->ListParts();
  delete min_product;
  min_product = nullptr;

  // build product
  director.BuildFullFeaturedProduct();

  // get product
  Product* full_product = builder->GetProduct();
  full_product->ListParts();
  delete full_product;
  full_product = nullptr;

  // Remember, the Builder pattern can be used without a Director class.
  std::cout << "Building customized product..." << '\n';
  builder->ProducePartA();
  builder->ProducePartC();
  std::cout << "Done." << '\n';
  Product* custom_product = builder->GetProduct();
  custom_product->ListParts();
  delete custom_product;
  custom_product = nullptr;

  delete builder;
}

int main(int argc, char const *argv[]) {
  Director director;
  ClientCode(director);
  // Builder: Ready for a new build.
  // Director: Building basic product...
  // Done.
  // Builder: Ready for a new build.
  // Product parts: PartA
  //
  // Director: Building full featured product...
  // Done.
  // Builder: Ready for a new build.
  // Product parts: PartA, PartB, PartC
  //
  // Building customized product...
  // Done.
  // Builder: Ready for a new build.
  // Product parts: PartA, PartC

  return 0;
}
