#include "observer.hpp"
#include "observable.hpp"


int main(int argc, char const *argv[]) {
  PodcastA podcast("English broadcast");
  Student student(&podcast);
  podcast.Add(&student);

  podcast.NotifyObservers();

  podcast.SetName("Pop song");

  podcast.NotifyObservers();
  // heard English broadcast
  // heard Pop song

  return 0;
}
