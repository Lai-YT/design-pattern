#ifndef COMPUTER_BUILDER_HPP_
#define COMPUTER_BUILDER_HPP_

#include <iostream>
#include <memory>
#include <utility>

#include "computer.hpp"


class ComputerBuilder {
public:
  ComputerBuilder()
    :computer_(std::make_unique<Computer>()) {}

  virtual ComputerBuilder* BuildProcessor(Computer::Processor processor) = 0;
  virtual ComputerBuilder* BuildMemory(Computer::Memory memory) = 0;
  virtual ComputerBuilder* BuildGraphics(Computer::Graphics graphics) = 0;
  virtual ComputerBuilder* BuildStorage(Computer::Storage storage) = 0;

  std::unique_ptr<Computer> Build() {
    std::unique_ptr<Computer> computer = std::move(computer_);
    computer_ = std::make_unique<Computer>();
    std::cout << "End building." << '\n';
    return computer;
  }

protected:
  std::unique_ptr<Computer> computer_;
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
