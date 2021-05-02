#include <iostream>

#include "observer.hpp"

Student::Student(IObservable* observable)
  :observable_(observable)
{}

void Student::Update() const {
  std::cout << "heard " + observable_->GetName() << '\n';
}
