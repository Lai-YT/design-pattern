#include <iostream>

#include "handler.hpp"


void ClientCode(Handler& handler) {
  for (const std::string& food : {"Nut", "Banana", "Cup of coffee"}) {
    std::cout << "Client: Who wants a " << food << "?\n";
    const std::string result = handler.Handle(food);
    if (!result.empty()) {
      std::cout << "  " << result << '\n';
    } else {
      std::cout << "  " << food << " was left untouched." << '\n';
    }
  }
}


// The other part of the client code constructs the actual chain.
int main(int argc, char const *argv[]) {
  MonkeyHandler monkey;
  SquirrelHandler squirrel;
  DogHandler dog;

  monkey.SetNext(&squirrel)->SetNext(&dog);

  // The client should be able to send a request to any handler, not just the
  // first one in the chain.
  std::cout << "Chain: Monkey -> Squirrel -> Dog" << '\n';
  ClientCode(monkey);
  std::cout << '\n';

  std::cout << "Subchain: Squirrel -> Dog" << '\n';
  ClientCode(squirrel);
  // Chain: Monkey -> Squirrel -> Dog
  // Client: Who wants a Nut?
  //   Squirrel: I'll eat the Nut.
  // Client: Who wants a Banana?
  //
  //   Monkey: I'll eat the Banana.
  // Client: Who wants a Cup of coffee?
  //   Cup of coffee was left untouched.
  //
  // Subchain: Squirrel -> Dog
  // Client: Who wants a Nut?
  //   Squirrel: I'll eat the Nut.
  // Client: Who wants a Banana?
  //   Banana was left untouched.
  // Client: Who wants a Cup of coffee?
  //   Cup of coffee was left untouched.

  return 0;
}
