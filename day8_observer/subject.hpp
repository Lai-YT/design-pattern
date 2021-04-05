#ifndef SUBJECT_HPP_
#define SUBJECT_HPP_

#include <list>
#include <string>

class IObserver;  // include "observer.hpp" in the .cpp file

class ISubject {
public:
  virtual ~ISubject() = default;
  virtual void Attach(IObserver *observer) = 0;
  virtual void Detach(IObserver *observer) = 0;
  virtual void Notify() = 0;
};

class Subject : public ISubject {
public:
  Subject() = default;
  virtual ~Subject();
  void Attach(IObserver *observer) override;
  void Detach(IObserver *observer) override;
  void Notify() override;
  void CreateMessage(std::string message = "Empty");
  void HowManyObserver() const;
  void SomeBusinessLogic();

private:
    std::list<IObserver *> list_observer_;
    std::string message_;
};

#endif /* end of include guard: SUBJECT_HPP_ */
