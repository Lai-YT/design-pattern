#ifndef COMPUTER_SELLER_HPP_
#define COMPUTER_SELLER_HPP_

#include <iostream>

#include "computer_builder.hpp"
#include "computer.hpp"


class ComputerSeller {
public:
  ComputerSeller(ComputerBuilder* computer_builder)
    :computer_builder_(computer_builder) {}

  Computer* LowSpec() {
    std::cout << "Start building low spec computer..." << '\n';
    return computer_builder_
           ->BuildProcessor(Computer::Processor("2.2GHz, 6 core, Intel Core i7"))
           ->BuildMemory(Computer::Memory(16))
           ->BuildGraphics(Computer::Graphics("Radeon Pro 555X, 4GB GDDR5"))
           ->BuildStorage(Computer::Storage(256))
           ->Build();
  }

  Computer* HighSpec() {
    std::cout << "Start building high spec computer..." << '\n';
    return computer_builder_
           ->BuildProcessor(Computer::Processor("2.6GHz, 6 core, Intel Core i7"))
           ->BuildMemory(Computer::Memory(16))
           ->BuildGraphics(Computer::Graphics("Radeon Pro 560X, 4GB GDDR5"))
           ->BuildStorage(Computer::Storage(512))
           ->Build();
  }

private:
  ComputerBuilder* computer_builder_;
};

#endif /* end of include guard: COMPUTER_SELLER_HPP_ */
