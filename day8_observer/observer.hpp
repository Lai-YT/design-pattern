#ifndef OBSERVER_HPP_
#define OBSERVER_HPP_

#include <string>

class Subject;

class IObserver {
public:
  virtual ~IObserver() = default;
  virtual void Update(const std::string &message_from_subject) = 0;
};

class Observer : public IObserver {
public:
  Observer(Subject &subject);
  virtual ~Observer();
  void Update(const std::string &message_from_subject) override;
  void RemoveMeFromTheList();
  void PrintInfo();

private:
  std::string message_from_subject_;
  Subject &subject_;
  static int static_number_ ;
  int number_;
};

#endif /* end of include guard: OBSERVER_HPP_ */
