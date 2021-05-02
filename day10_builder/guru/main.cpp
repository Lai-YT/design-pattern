// It makes sense to use the Builder pattern only when your products are quite
// complex and require extensive configuration.

#include <memory>

#include "builder.hpp"
#include "director.hpp"
#include "product.hpp"

// The client code creates a builder object, passes it to the director and then
// initiates the construction process. The end result is retrieved from the
// builder object.
void ClientCode(Director& director) {
  auto builder = std::make_shared<ConcreteBuilder>();
  director.SetBuilder(builder);

  director.BuildMinimalViableProduct();
  std::unique_ptr<Product> min_product = builder->GetProduct();
  min_product->ListParts();

  director.BuildFullFeaturedProduct();
  std::unique_ptr<Product> full_product = builder->GetProduct();
  full_product->ListParts();

  // Remember, the Builder pattern can be used without a Director class.
  std::cout << "Building customized product..." << '\n';
  builder->ProducePartA();
  builder->ProducePartC();
  std::cout << "Done." << '\n';
  std::unique_ptr<Product> custom_product = builder->GetProduct();
  custom_product->ListParts();
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
