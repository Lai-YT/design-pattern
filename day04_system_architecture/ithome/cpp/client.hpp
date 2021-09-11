#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <cctype>

#include "Drink.hpp"

class Client {
public:
  Drink* order(std::string drink, SugarType sugar_type, IceType ice_type) {
    for (char& c : drink) {
      c = std::tolower(c);
    }

    if (drink == "tea") {
      return new Tea(sugar_type, ice_type);
    } else if (drink == "coffee") {
      return new Coffee(sugar_type, ice_type);
    } else {
      return nullptr;
    }

  }

};

#endif /* end of include guard: CLIENT_HPP_ */
