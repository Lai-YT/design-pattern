#ifndef PROTOTYPE_FACTORY_HPP_
#define PROTOTYPE_FACTORY_HPP_

#include <memory>
#include <unordered_map>

#include "prototype.hpp"


enum class Type {
  PROTOTYPE_1,
  PROTOTYPE_2
};


// In PrototypeFactory you have 2 concrete prototypes, one for each concrete
// prototype class. So each time you want to create a bullet, you can use the
// existing ones and clone those.
class PrototypeFactory {
public:
  // Notice here that you just need to specify the type of the prototype you
  // want and the method will create from the object with this type.
  std::unique_ptr<Prototype> CreatePrototype(const Type type) const {
    // The return type of unordered_map::at has const qualified version,
    // while operator[] doesn't.
    return prototypes_.at(type)->Clone();
  }

  PrototypeFactory() {
    // One may also use unordered_map::emplace, but may be less expressive?
    prototypes_[Type::PROTOTYPE_1] = std::make_unique<ConcretePrototype1>("PROTOTYPE_1", 50.f);
    prototypes_[Type::PROTOTYPE_2] = std::make_unique<ConcretePrototype2>("PROTOTYPE_2", 60.f);
  }

private:
  std::unordered_map<Type, std::unique_ptr<Prototype>> prototypes_;

};


#endif /* end of include guard: PROTOTYPE_FACTORY_HPP_ */
