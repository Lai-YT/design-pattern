// codes from the link below:
// https://refactoring.guru/design-patterns/observer/cpp/example

#include "observer.hpp"
#include "subject.hpp"

void ClientCode() {
  Subject *subject = new Subject;
  Observer *observer1 = new Observer(*subject);
  Observer *observer2 = new Observer(*subject);
  Observer *observer3 = new Observer(*subject);

  subject->CreateMessage("Hello World! :D");
  observer3->RemoveMeFromTheList();

  subject->CreateMessage("The weather is hot today! :P");
  Observer *observer4 = new Observer(*subject);

  observer2->RemoveMeFromTheList();
  Observer *observer5 = new Observer(*subject);

  subject->CreateMessage("My new car is great :)");

  observer5->RemoveMeFromTheList();
  observer4->RemoveMeFromTheList();
  observer1->RemoveMeFromTheList();

  delete observer5;
  delete observer4;
  delete observer3;
  delete observer2;
  delete observer1;
  delete subject;
}

int main(int argc, char const *argv[]) {

  ClientCode();
  // Hi, I'm the Observer "1".
  // Hi, I'm the Observer "2".
  // Hi, I'm the Observer "3".
  // There are 3 observers in the list.
  // Observer "1": a new message is available --> Hello World! :D
  // Observer "2": a new message is available --> Hello World! :D
  // Observer "3": a new message is available --> Hello World! :D
  // Observer "3" removed from the list.
  // There are 2 observers in the list.
  // Observer "1": a new message is available --> The weather is hot today! :P
  // Observer "2": a new message is available --> The weather is hot today! :P
  // Hi, I'm the Observer "4".
  // Observer "2" removed from the list.
  // Hi, I'm the Observer "5".
  // There are 3 observers in the list.
  // Observer "1": a new message is available --> My new car is great :)
  // Observer "4": a new message is available --> My new car is great :)
  // Observer "5": a new message is available --> My new car is great :)
  // Observer "5" removed from the list.
  // Observer "4" removed from the list.
  // Observer "1" removed from the list.
  // Goodebye, I was the Observer "5".
  // Goodebye, I was the Observer "4".
  // Goodebye, I was the Observer "3".
  // Goodebye, I was the Observer "2".
  // Goodebye, I was the Observer "1".
  // Goodebye, I was the subject.
  return 0;
}
