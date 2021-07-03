#include <iostream>
#include <memory>

#include "proxy.hpp"
#include "subject.hpp"


// The client code is supposed to work with all objects (both subjects and
// proxies) via the Subject interface in order to support both real subjects and
// proxies. In real life, however, clients mostly work with their real subjects
// directly. In this case, to implement the pattern more easily, you can extend
// your proxy from the real subject's class.
void ClientCode(const Subject& subject) {
  subject.Request();
}


int main(int argc, char const *argv[]) {
  std::cout << "Client: Executing the client code with a real subject." << '\n';
  auto real_subject = std::make_unique<RealSubject>();
  ClientCode(*real_subject);
  std::cout << '\n';

  std::cout << "Client: Executing the same client code with a proxy." << '\n';
  auto proxy = std::make_unique<Proxy>(*real_subject);
  ClientCode(*proxy);
  // Client: Executing the client code with a real subject.
  // RealSubject: Handling request.
  //
  // Client: Executing the same client code with a proxy.
  // Proxy: Checking access prior to firing a real request.
  // RealSubject: Handling request.
  // Proxy: Logging the time of request.

  return 0;
}
