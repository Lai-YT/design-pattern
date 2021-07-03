#ifndef SUBJECT_HPP_
#define SUBJECT_HPP_

#include <iostream>


// The Subject interface declares common operations for both RealSubject and the
// Proxy. As long as the client works with RealSubject using this interface,
// you'll be able to pass it a proxy instead of a real subject.
class Subject {
public:
  virtual void Request() const = 0;
};


// The RealSubject contains some core business logic. Usually, RealSubjects are
// capable of doing some useful work which may also be very slow or sensitive -
// e.g. correcting input data. A Proxy can solve these issues without any
// changes to the RealSubject's code.
class RealSubject : public Subject {
public:
  void Request() const override {
    std::cout << "RealSubject: Handling request." << '\n';
  }
};


#endif /* end of include guard: SUBJECT_HPP_ */
