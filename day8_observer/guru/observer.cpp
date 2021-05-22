#include <iostream>

#include "observer.hpp"
#include "subject.hpp"


Observer::Observer(Subject& subject)
  :subject_(subject) {
  subject_.Attach(this);
  number_ = ++Observer::static_number_;
  std::cout << "Hi, I'm the Observer \"" << number_ << "\".\n";
}

Observer::~Observer() {
  std::cout << "Goodebye, I was the Observer \"" << number_ << "\".\n";
}

void Observer::Update(const std::string& message_from_subject) {
  message_from_subject_ = message_from_subject;
  this->PrintInfo();
}

void Observer::RemoveMeFromTheList() {
  subject_.Detach(this);
  std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
}

void Observer::PrintInfo() {
  std::cout << "Observer \"" << number_ << "\": a new message is available --> "
            << message_from_subject_ << '\n';
}

int Observer::static_number_ = 0;
