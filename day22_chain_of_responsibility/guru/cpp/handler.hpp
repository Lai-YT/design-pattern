#ifndef HANDLER_HPP_
#define HANDLER_HPP_

#include <string>

// The Handler interface declares a method for building the chain of handlers.
// It also declares a method for executing a request.
class Handler {
public:
  virtual Handler* SetNext(Handler* const handler) = 0;
  virtual std::string Handle(const std::string& request) = 0;
};


// The default chaining behavior can be implemented inside a base handler class.
class AbstractHandler : public Handler {
public:
  Handler* SetNext(Handler* const handler) override {
    next_handler_ = handler;
    // Returning a handler from here will let us link handlers in a convenient
    // way like this:
    // monkey->setNext(squirrel)->setNext(dog);
    return handler;
  }

  std::string Handle(const std::string& request) override {
    if (!next_handler_) {
      return "";
    }
    return next_handler_->Handle(request);
  }

  AbstractHandler() = default;

private:
  Handler* next_handler_ = nullptr;

};


// All Concrete Handlers either handle a request or pass it to the next handler
// in the chain.
class MonkeyHandler : public AbstractHandler {
public:
  std::string Handle(const std::string& request) override {
    if (request == "Banana") {
      return "Monkey: I'll eat the " + request + '.';
    } else {
      return AbstractHandler::Handle(request);
    }
  }
};


class SquirrelHandler : public AbstractHandler {
public:
  std::string Handle(const std::string& request) override {
    if (request == "Nut") {
      return "Squirrel: I'll eat the " + request + '.';
    } else {
      return AbstractHandler::Handle(request);
    }
  }
};


class DogHandler : public AbstractHandler {
public:
  std::string Handle(const std::string& request) override {
    if (request == "MeatBall") {
      return "Dog: I'll eat the " + request + '.';
    } else {
      return AbstractHandler::Handle(request);
    }
  }
};


#endif /* end of include guard: HANDLER_HPP_ */
