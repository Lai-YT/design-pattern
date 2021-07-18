#ifndef CARETAKER_HPP_
#define CARETAKER_HPP_

#include <memory>
#include <vector>

#include "memento.hpp"
#include "originator.hpp"

// The Caretaker doesn't depend on the Concrete Memento class. Therefore, it
// doesn't have access to the originator's state, stored inside the memento. It
// works with all mementos via the base Memento interface.
class Caretaker {
public:
  void Backup() {
    std::cout << "Caretaker: Saving Originator's state..." << '\n';
    mementos_.push_back(originator_.Save());
  }

  void Undo() {
    if (mementos_.empty()) {
      return;
    }
    std::unique_ptr<Memento> memento = std::move(mementos_.back());
    mementos_.pop_back();
    std::cout << "Caretaker: Restoring state to " << memento->name() << '\n';
    try {
      originator_.Restore(memento);
    } catch (...) {
      Undo();
    }
  }

  void ShowHistory() const {
    std::cout << "Caretaker: Here's the list of mementos." << '\n';
    for (const auto& memento : mementos_) {
      std::cout << memento->name() << '\n';
    }
  }

  Caretaker(Originator& originator)
    :originator_(originator) {}

private:
  Originator& originator_;
  std::vector<std::unique_ptr<Memento>> mementos_;
};


#endif /* end of include guard: CARETAKER_HPP_ */
