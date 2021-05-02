#ifndef COMPUTER_HPP_
#define COMPUTER_HPP_

#include <iostream>
#include <string>

class Computer {
public:
  Computer() = default;
  ~Computer() = default;

  class Processor {
  public:
    Processor(std::string name = "")
      :name_(name) {}

    std::string name() const {
      return name_;
    }

  private:
    std::string name_;
  };

  // nested classes
  class Memory {
  public:
    Memory(int size = 0)
      :size_(size) {}

    int size() const {
      return size_;
    }

  private:
    int size_;
  };

  class Graphics {
  public:
    Graphics(std::string name = "")
      :name_(name) {}

    std::string name() const {
      return name_;
    }

  private:
    std::string name_;
  };

  class Storage {
  public:
    Storage(int size = 0)
      :size_(size) {}

    int size() const {
      return size_;
    }

  private:
    int size_;
  };

  void SetProcessor(Processor processor) {
    std::cout << "Setting processor..." << '\n';
    processor_ = processor;
  }

  void SetMemory(Memory memory) {
    std::cout << "Setting memory..." << '\n';
    memory_ = memory;
  }

  void SetGraphics(Graphics graphics) {
    std::cout << "Setting graphics..." << '\n';
    graphics_ = graphics;
  }

  void SetStorage(Storage storage) {
    std::cout << "Setting storage..." << '\n';
    storage_ = storage;
  }

  void ShowDetails() const {
    std::cout << "Computer:\n \
                  Processor: " << processor_.name() << "\n \
                  Memory size: " << std::to_string(memory_.size()) << "GB\n \
                  Graphics: " << graphics_.name() << "\n \
                  Storage size: " << std::to_string(storage_.size()) << "GB\n";
  }

private:
  Processor processor_;
  Memory memory_;
  Storage storage_;
  Graphics graphics_;
};

#endif /* end of include guard: COMPUTER_HPP_ */
