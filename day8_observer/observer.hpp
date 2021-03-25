#ifndef OBSERVER_HPP_
#define OBSERVER_HPP_

#include "observable.hpp"

class IObservable;

class IObserver {
public:
  IObserver() = default;
  virtual ~IObserver() = default;

  virtual void Update() const = 0;
};

class Student : public IObserver {
public:
  Student(IObservable* observable);
  virtual ~Student();

  void Update() const override;

private:
  IObservable* observable_;
};

#endif /* end of include guard: OBSERVER_HPP_ */
