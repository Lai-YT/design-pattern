#include <iostream>
#include <string>

#include "computer_builder.hpp"
#include "computer.hpp"
#include "computer_seller.hpp"

void ClientCode() {
  ConcreteComputerBuilder* concrete_computer_builder = new ConcreteComputerBuilder();

  ComputerSeller computer_seller(concrete_computer_builder);

  Computer* low_spec_computer = computer_seller.LowSpec();
  low_spec_computer->ShowDetails();


  Computer* high_spec_computer = computer_seller.HighSpec();
  high_spec_computer->ShowDetails();

  std::cout << "Start builing customized computer..." << '\n';
  Computer* custom_computer = concrete_computer_builder
                              ->BuildProcessor(Computer::Processor("2.9GHz, 6 core, Intel Core i9"))
                              ->BuildMemory(Computer::Memory(32))
                              ->BuildGraphics(Computer::Graphics("Radeon Pro 560X, 4GB GDDR5"))
                              ->BuildStorage(Computer::Storage(4096))
                              ->Build();
  custom_computer->ShowDetails();

  delete low_spec_computer;
  delete high_spec_computer;
  delete custom_computer;
  delete concrete_computer_builder;
}

int main(int argc, char const *argv[]) {
  ClientCode();
  // Start building low spec computer...
  // Setting processor...
  //
  // Setting memory...
  // Setting graphics...
  // Setting storage...
  // End building.
  // Computer:
  //                    Processor: 2.2GHz, 6 core, Intel Core i7
  //                    Memory size: 16GB
  //                    Graphics: Radeon Pro 555X, 4GB GDDR5
  //                    Storage size: 256GB
  // Start building high spec computer...
  // Setting processor...
  // Setting memory...
  // Setting graphics...
  // Setting storage...
  // End building.
  // Computer:
  //                    Processor: 2.6GHz, 6 core, Intel Core i7
  //                    Memory size: 16GB
  //                    Graphics: Radeon Pro 560X, 4GB GDDR5
  //                    Storage size: 512GB
  // Start builing customized computer...
  // Setting processor...
  // Setting memory...
  // Setting graphics...
  // Setting storage...
  // End building.
  // Computer:
  //                    Processor: 2.9GHz, 6 core, Intel Core i9
  //                    Memory size: 32GB
  //                    Graphics: Radeon Pro 560X, 4GB GDDR5
  //                    Storage size: 4096GB

  return 0;
}
