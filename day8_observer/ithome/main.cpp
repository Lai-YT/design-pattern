#include "observer.hpp"
#include "observable.hpp"

int main(int argc, char const *argv[]) {
  IObservable* podcast = new PodcastA("English broadcast");
  IObserver* student = new Student(podcast);
  podcast->Add(student);

  podcast->NotifyObservers();

  podcast->SetName("Pop song");

  podcast->NotifyObservers();

  delete podcast;
  delete student;

  return 0;
}
