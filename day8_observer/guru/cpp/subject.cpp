#include <iostream>
#include <list>

#include "observer.hpp"
#include "subject.hpp"


Subject::~Subject() {
  std::cout << "Goodebye, I was the subject." << '\n';
}

void Subject::Attach(IObserver* observer) {
  list_observer_.push_back(observer);
}

void Subject::Detach(IObserver* observer) {
  list_observer_.remove(observer);
}

void Subject::Notify() {
  this->HowManyObserver();
  for (IObserver* observer : list_observer_) {
    observer->Update(message_);
  }
}

void Subject::CreateMessage(const std::string& message) {
  message_ = message;
  this->Notify();
}

void Subject::HowManyObserver() const {
  std::cout << "There are " << list_observer_.size()
            << " observers in the list." << '\n';
}

void Subject::SomeBusinessLogic() {
  message_ = "change message message";
  this->Notify();
  std::cout << "I'm about to do something important" << '\n';
}
