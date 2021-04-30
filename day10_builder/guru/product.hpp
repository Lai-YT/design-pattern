#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include <iostream>
#include <string>
#include <vector>

class Product {
public:
  Product() = default;

  void AddPart(const std::string& part) {
    parts_.push_back(part);
  }

  void ListParts() const {
    std::cout << "Product parts: ";
    for (size_t i = 0; i < parts_.size() - 1; i++) {
      std::cout << parts_.at(i) << ", ";
    }
    std::cout << parts_.back() << "\n\n";
  }

private:
  std::vector<std::string> parts_;
};

#endif /* end of include guard: PRODUCT_HPP_ */
