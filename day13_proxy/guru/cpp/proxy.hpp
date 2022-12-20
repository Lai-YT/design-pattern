#ifndef PROXY_HPP_
#define PROXY_HPP_

#include <iostream>
#include <memory>

#include "subject.hpp"


// The Proxy has an interface identical to the RealSubject.
class Proxy : public Subject {
public:
  // The most common applications of the Proxy pattern are lazy loading,
  // caching, controlling the access, logging, etc. A Proxy can perform one of
  // these things and then, depending on the result, pass the execution to the
  // same method in a linked RealSubject object.
  void Request() const override {
    if (CheckAccess_()) {
      real_subject_->Request();
      LogAccess_();
    }
  }

  // The Proxy maintains a reference to an object of the RealSubject class.
  // It can be either lazy-loaded or passed to the Proxy by the client.
  Proxy(const RealSubject& real_subject)
    :real_subject_(std::make_unique<RealSubject>(real_subject)) {}

private:
  bool CheckAccess_() const {
    // Some real checks should go here.
    std::cout << "Proxy: Checking access prior to firing a real request." << '\n';
    return true;
  }

  void LogAccess_() const {
    std::cout << "Proxy: Logging the time of request." << '\n';
  }

  std::unique_ptr<RealSubject> real_subject_;
};


#endif /* end of include guard: PROXY_HPP_ */
