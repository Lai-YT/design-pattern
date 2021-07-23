#ifndef FLYWEIGHT_HPP_
#define FLYWEIGHT_HPP_

#include <initializer_list>
#include <iostream>
#include <unordered_map>

#include "state.hpp"

// The Flyweight stores a common portion of the state (also called intrinsic
// state) that belongs to multiple real business entities. The Flyweight accepts
// the rest of the state (extrinsic state, unique for each entity) via its
// method parameters.
class Flyweight {
public:
  const SharedState& shared_state() const {
    return shared_state_;
  }

  void Operation(const UniqueState& unique_state) const {
    std::cout << "Flyweight: Displaying shared (" << shared_state_ << ") and unique (" << unique_state << ") state." << '\n';
  }

  Flyweight(const SharedState& shared_state)
    :shared_state_(shared_state) {}

private:
  const SharedState& shared_state_;
};

// The Flyweight Factory creates and manages the Flyweight objects. It ensures
// that flyweights are shared correctly. When the client requests a flyweight,
// the factory either returns an existing instance or creates a new one, if it
// doesn't exist yet.
class FlyweightFactory {
public:
  // Returns an existing Flyweight with a given state or creates a new one.
  const Flyweight& GetFlyweight(const SharedState& shared_state) {
    const std::string key = GenerateKey_(shared_state);
    if (flyweights_.find(key) == flyweights_.end()) {
      std::cout << "FlyweightFactory: Can't find the flyweight. Create a new one." << '\n';
      flyweights_.emplace(key, Flyweight(shared_state));
    } else {
      std::cout << "FlyweightFactory: Reuse the existing flyweight." << '\n';
    }
    return flyweights_.at(key);
  }

  void ListFlyweights() const {
    std::cout << "FlyweightFactory: I have " << flyweights_.size() << " flyweights." << '\n';
    for (const auto& pair : flyweights_) {
      std::cout << pair.first << '\n';
    }
  }

  FlyweightFactory(const std::initializer_list<SharedState>& shared_states) {
    for (const auto& ss: shared_states) {
      flyweights_.emplace(GenerateKey_(ss), Flyweight(ss));
    }
  }

private:
  // Returns a Flyweight's string hash for a given state.
  std::string GenerateKey_(const SharedState& ss) const {
    return ss.brand() + '_' + ss.model() + '_' + ss.color();
  }

  std::unordered_map<std::string, const Flyweight> flyweights_;
};


#endif /* end of include guard: FLYWEIGHT_HPP_ */
