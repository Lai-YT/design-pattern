#include <iostream>

#include "observer.hpp"

Student::Student(IObservable* observable)
  :observable_(observable)
{}

Student::~Student() {
  delete observable_;
}

void Student::Update() const {
  std::cout << "heard" + observable_->GetName() << '\n';
}
