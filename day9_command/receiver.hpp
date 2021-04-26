#ifndef RECEIVER_HPP_
#define RECEIVER_HPP_

// The Receiver classes contain some important business logic. They know how to
// perform all kinds of operations, associated with carrying out a request. In
// fact, any class may serve as a Receiver.
class Receiver {
public:
  void DoSomething(const std::string& a) {
    std::cout << "Receiver: Working on (" << a << ")\n";
  }

  void DoSomethingElse(const std::string& b) {
    std::cout << "Receiver: Also working on (" << b << ")\n";
  }
};

#endif /* end of include guard: RECEIVER_HPP_ */
