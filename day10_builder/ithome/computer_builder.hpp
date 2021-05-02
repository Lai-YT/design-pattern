#ifndef COMPUTER_BUILDER_HPP_
#define COMPUTER_BUILDER_HPP_

#include <iostream>

#include "computer.hpp"


// Builders take no respnsibility for memory management
class ComputerBuilder {
public:
  ComputerBuilder()
    :computer_(new Computer()) {}

  virtual ~ComputerBuilder() {
    delete computer_;
  }

  virtual ComputerBuilder* BuildProcessor(Computer::Processor processor) = 0;
  virtual ComputerBuilder* BuildMemory(Computer::Memory memory) = 0;
  virtual ComputerBuilder* BuildGraphics(Computer::Graphics graphics) = 0;
  virtual ComputerBuilder* BuildStorage(Computer::Storage storage) = 0;

  Computer* Build() {
    Computer* computer = computer_;
    computer_ = new Computer();
    std::cout << "End building." << '\n';
    return computer;
  }

protected:
  Computer* computer_;
};


class ConcreteComputerBuilder : public ComputerBuilder {
public:
  ConcreteComputerBuilder() = default;
  ~ConcreteComputerBuilder() = default;

  ComputerBuilder* BuildProcessor(Computer::Processor processor) override {
    computer_->SetProcessor(processor);
    return this;
  }

  ComputerBuilder* BuildMemory(Computer::Memory memory) override {
    computer_->SetMemory(memory);
    return this;
  }

  ComputerBuilder* BuildGraphics(Computer::Graphics graphics) override {
    computer_->SetGraphics(graphics);
    return this;
  }

  ComputerBuilder* BuildStorage(Computer::Storage storage) override {
    computer_->SetStorage(storage);
    return this;
  }
};

#endif /* end of include guard: COMPUTER_BUILDER_HPP_ */
