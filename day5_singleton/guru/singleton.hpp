#ifndef SINGLETON_HPP_
#define SINGLETON_HPP_

#include <iostream>
#include <memory>
#include <mutex>
#include <string>

// The Singleton class defines the `GetInstance` method that serves as an
// alternative to constructor and lets clients access the same instance of this
// class over and over.
class Singleton {
public:
  // Singletons should not be cloneable.
  Singleton(const Singleton &) = delete;

  // Singletons should not be assignable.
  Singleton& operator= (const Singleton &) = delete;

  // This is the static method that controls the access to the singleton
  // instance. On the first run, it creates a singleton object and places it
  // into the static field. On subsequent runs, it returns the client existing
  // object stored in the static field.
  static std::shared_ptr<Singleton> GetInstance(const std::string& value) {
    // lock the current thread
    std::lock_guard<std::mutex> inst_lock(inst_mutex);

    // This is a safer way to create an instance. instance = new Singleton is
    // dangeruous in case two instance threads wants to access at the same time.
    if (!singleton_) {
      std::cout << "Generating new instance..." << '\n';
      
      // std::make_shared can't be used since the ctor is private
      singleton_ = std::shared_ptr<Singleton>(new Singleton(value));
    }
    return singleton_;
  }

  // Finally, any singleton should define some business logic, which can be
  // executed on its instance.
  void SomeBusinessLogic() {
    std::cout << "Do some business logic." << '\n';
  }

  std::string value() const {
    return value_;
  }

private:
  std::string value_;
  static std::shared_ptr<Singleton> singleton_;
  static std::mutex inst_mutex;


  // The Singleton's constructor should always be private to prevent direct
  // construction calls with the "new" operator.
  Singleton(const std::string& value)
    :value_(value) {}
};

std::shared_ptr<Singleton> Singleton::singleton_ = nullptr;
std::mutex Singleton::inst_mutex;

#endif /* end of include guard: SINGLETON_HPP_ */
