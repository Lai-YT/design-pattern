#ifndef OBSERVABLE_HPP_
#define OBSERVABLE_HPP_

#include <list>
#include <string>

#include "observer.hpp"

class IObserver;

class IObservable {
public:
  IObservable() = default;
  virtual ~IObservable() = default;

  virtual void Add(IObserver* observer) = 0;
  virtual void NotifyObservers() = 0;
  virtual std::string GetName() const = 0;
};

class PodcastA : public IObservable {
public:
  PodcastA() = default;
  virtual ~PodcastA();

  void Add(IObserver* observer) override;
  void NotifyObservers() override;
  std::string GetName() const override;

private:
  std::list<IObserver*> observers_;
  std::string name_ = "English broadcast";
};

#endif /* end of include guard: OBSERVABLE_HPP_ */
