#include <list>
#include <string>

#include "observable.hpp"

PodcastA::~PodcastA() {
    for (IObserver* obs : observers_) {
      delete obs;
    }
  }

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
