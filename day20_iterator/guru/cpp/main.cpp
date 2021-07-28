#include <iostream>

#include "container.hpp"
#include "iterator.hpp"

// The client code may or may not know about the Concrete Iterator or Collection
// classes, for this implementation the container is generic so you can used
// with an int or with a custom class.
template<typename T>
void Iteration(Container<T>& container, const bool reverse) {
  for (auto itr = container.CreateIterator(reverse); !itr.IsDone(); itr.Next()) {
    std::cout << *itr << ' ';
  }
  std::cout << '\n';
}

// custom data class
class IntWrapper {
public:
  int value() const {
    return value_;
  }

  IntWrapper(const int value = 0)
    :value_(value) {}

private:
  int value_;
};

std::ostream& operator<<(std::ostream& os, const IntWrapper& int_wrapper) {
  return os << int_wrapper.value();
}


int main(int argc, char const *argv[]) {
  Container<int> container_1;
  for (int i = 0; i < 10; ++i) {
    container_1.Add(i);
  }
  std::cout << "Iterator with int:" << '\n';
  Iteration(container_1, false);
  std::cout << "Reverse iterator with int:" << '\n';
  Iteration(container_1, true);
  std::cout << '\n';

  Container<IntWrapper> container_2;
  for (int i = 1; i <= 10000000; i *= 10) {
    container_2.Add(IntWrapper(i));
  }
  std::cout << "Iterator with custom class:" << '\n';
  Iteration(container_2, false);
  std::cout << "Reverse iterator with custom class:" << '\n';
  Iteration(container_2, true);
  // Tterator with int:
  // 0 1 2 3 4 5 6 7 8 9
  // Reverse iterator with int:
  // 9 8 7 6 5 4 3 2 1 0
  //
  // Iterator with custom class:
  // 1 10 100 1000 10000 100000 1000000 10000000
  // Reverse iterator with custom class:
  // 10000000 1000000 100000 10000 1000 100 10 1

  return 0;
}
