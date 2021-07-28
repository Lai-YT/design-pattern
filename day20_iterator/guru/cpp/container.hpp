#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_

// Generic Collections/Containers provides one or several methods for retrieving
// fresh iterator instances, compatible with the collection class.

#include <vector>

#include "iterator.hpp"


template<typename T>
class Container {
  friend class Iterator<T, Container>;

public:
  void Add(const T& a) {
    data_.push_back(a);
  }

  Iterator<T, Container> CreateIterator(bool reverse = false) {
    return Iterator<T, Container>(*this, reverse);
  }

private:
  std::vector<T> data_;
};


#endif /* end of include guard: CONTAINER_HPP_ */
