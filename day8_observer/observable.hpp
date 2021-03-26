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
  virtual void SetName(std::string name) = 0;
};

class PodcastA : public IObservable {
public:
  PodcastA(std::string name);
  virtual ~PodcastA() = default;

  void Add(IObserver* observer) override;
  void NotifyObservers() override;
  std::string GetName() const override;
  void SetName(std::string name) override;

private:
  std::list<IObserver*> observers_;
  std::string name_;
};

#endif /* end of include guard: OBSERVABLE_HPP_ */
