#ifndef STATE_HPP_
#define STATE_HPP_

#include <ostream>
#include <string>


// intrinsic state
class SharedState {
public:
  std::string brand() const {
    return brand_;
  }

  std::string model() const {
    return model_;
  }

  std::string color() const {
    return color_;
  }

  SharedState(const std::string& brand, const std::string& model, const std::string& color)
    :brand_(brand),model_(model),color_(color) {}

private:
  std::string brand_;
  std::string model_;
  std::string color_;
};

std::ostream& operator<<(std::ostream& os, const SharedState& ss) {
  return os << "[ " << ss.brand() << ", " << ss.model() << ", " << ss.color() << " ]";
}


// extrinsic state
class UniqueState {
public:
  std::string owner() const {
    return owner_;
  }

  std::string plates() const {
    return plates_;
  }

  UniqueState(const std::string& owner, const std::string& plates)
    :owner_(owner),plates_(plates) {}

private:
  std::string owner_;
  std::string plates_;
};

std::ostream& operator<<(std::ostream& os, const UniqueState& us) {
  return os << "[ "  << us.owner() << ", " << us.plates() << " ]";
}


#endif /* end of include guard: STATE_HPP_ */
