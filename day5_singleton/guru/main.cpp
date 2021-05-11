#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

#include "singleton.hpp"


void ThreadFoo() {
  // Following code emulates slow initialization.
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::shared_ptr<Singleton> singleton = Singleton::GetInstance("FOO");
  std::cout << singleton->value() << '\n';
}

void ThreadBar() {
  // Following code emulates slow initialization.
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::shared_ptr<Singleton> singleton = Singleton::GetInstance("BAR");
  std::cout << singleton->value() << '\n';
}

int main(int argc, char const *argv[]) {
  std::cout << "If you see the same value, then singleton was reused;\n"
            << "if you see different values, then 2 singletons were created.\n\n"
            << "Result:" << '\n';

  std::thread t1(ThreadFoo);
  std::thread t2(ThreadBar);
  t1.join();
  t2.join();

  return 0;
}
