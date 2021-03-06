#include <list>
#include <string>

#include "observable.hpp"


PodcastA::PodcastA(const std::string& name)
  :name_(name) {}

void PodcastA::Add(IObserver* observer) {
  observers_.push_back(observer);
}

void PodcastA::NotifyObservers() {
  for (IObserver* obs : observers_) {
    obs->Update();
  }
}

std::string PodcastA::GetName() const {
  return name_;
}

void PodcastA::SetName(const std::string& name) {
  name_ = name;
}
