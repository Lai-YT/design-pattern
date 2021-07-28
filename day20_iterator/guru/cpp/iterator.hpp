#ifndef ITERATOR_HPP_
#define ITERATOR_HPP_

// C++ has its own implementation of iterator that works with a different
// generics containers defined by the standard library.

#include <vector>


template<typename T, typename Container>
class Iterator {
public:
  void Next() {
    reverse_ ? --cur_iter_ : ++cur_iter_;
  }

  bool IsDone() const {
    return cur_iter_ == (reverse_ ? container_.data_.begin() - 1
                                  : container_.data_.end());
  }

  T& operator*() {
    return *cur_iter_;
  }

  Iterator(Container& container, const bool reverse = false)
    :container_(container),reverse_(reverse) {
    cur_iter_ = (reverse_ ? container_.data_.end() - 1
                          : container.data_.begin());
  }

private:
  Container& container_;
  typename std::vector<T>::iterator cur_iter_;
  bool reverse_;
};


#endif /* end of include guard: ITERATOR_HPP_ */
