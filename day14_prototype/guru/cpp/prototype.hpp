#ifndef PROTOTYPE_HPP_
#define PROTOTYPE_HPP_

#include <iostream>
#include <memory>
#include <string>


// The example class that has cloning ability.
// We'll see how the values of field with different types will be cloned.
class Prototype {
public:
  virtual std::unique_ptr<Prototype> Clone() const = 0;

  virtual void Method() const {
    std::cout << "Call Method from " << prototype_name_
              << " with field: " << prototype_field_ << '\n';
  }

  Prototype(const std::string& prototype_name, const float prototype_field)
    :prototype_name_(prototype_name),prototype_field_(prototype_field) {}

  virtual ~Prototype() = default;

protected:
  std::string prototype_name_;
  float prototype_field_;

private:
  // Since there's no covariant between smart pointers,
  // use this double transform technique to make it a smart pointer to base class.
  virtual Prototype* CloneImpl() const = 0;

};


// ConcretePrototype1 is a Sub-Class of Prototype and implement the Clone Method.
// In this example, all data members of Prototype Class are in the Stack.
// If you have pointers in your properties, ex: String* name_ ,
// you will need to implement the Copy-Constructor to make sure you have
// a deep copy from the clone method.
class ConcretePrototype1 : public Prototype {
public:
  // Notice that Clone method returns a Pointer to a new ConcretePrototype1
  // replica. So, the client (who call the clone method) has the responsability
  // to free that memory.
  // If you have smart pointer knowledge, you may prefer to use unique_pointer here.
  std::unique_ptr<Prototype> Clone() const override {
    return std::unique_ptr<Prototype>((this->CloneImpl()));
  }

  ConcretePrototype1(const std::string& prototype_name,
                     const float prototype_field)
    :Prototype(prototype_name, prototype_field) {}

private:
  ConcretePrototype1* CloneImpl() const override {
    return new ConcretePrototype1(*this);
  }

};


class ConcretePrototype2 : public Prototype {
public:
  std::unique_ptr<Prototype> Clone() const override {
    return std::unique_ptr<Prototype>(this->CloneImpl());
  }

  ConcretePrototype2(const std::string& prototype_name,
                     const float prototype_field)
    :Prototype(prototype_name, prototype_field) {}

private:
  ConcretePrototype2* CloneImpl() const override {
    return new ConcretePrototype2(*this);
  }

};


#endif /* end of include guard: PROTOTYPE_HPP_ */
