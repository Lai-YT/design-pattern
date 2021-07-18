#include <cstdlib>
#include <iostream>

#include "caretaker.hpp"
#include "memento.hpp"
#include "originator.hpp"


void ClientCode() {
  auto originator = Originator("Super-duper-super-puper-super");
  auto caretaker = Caretaker(originator);
  std::cout << '\n';

  caretaker.Backup();
  originator.DoSomething();
  std::cout << '\n';

  caretaker.Backup();
  originator.DoSomething();
  std::cout << '\n';

  caretaker.Backup();
  originator.DoSomething();
  std::cout << '\n';

  caretaker.ShowHistory();
  std::cout << '\n';

  std::cout << "Client: Now, let's rollback!" << '\n';
  caretaker.Undo();
  std::cout << '\n';

  std::cout << "Client: Once more!" << '\n';
  caretaker.Undo();
}


int main(int argc, char const *argv[]) {
  std::srand(std::time(0));
  ClientCode();
  // Originator: My initial state is Super-duper-super-puper-super
  //
  // Caretaker: Saving Originator's state...
  // Originator: I'm doing something important.
  // Originator: And my state has changed to ZytqiXve7N92uBo84YJdlgF9tRh9Y3.
  //
  // Caretaker: Saving Originator's state...
  // Originator: I'm doing something important.
  // Originator: And my state has changed to J62BwigpKoATo4ecAg9RKs7X1yyg6V.
  //
  // Caretaker: Saving Originator's state...
  // Originator: I'm doing something important.
  // Originator: And my state has changed to jNbjYVSDIm1SEpXqPfXW7pOCMPBJ3H.
  //
  // Caretaker: Here's the list of mementos.
  // Sun Jul 18 14:59:22 2021
  //  / (Super-dup...)
  // Sun Jul 18 14:59:22 2021
  //  / (ZytqiXve7...)
  // Sun Jul 18 14:59:22 2021
  //  / (J62BwigpK...)
  //
  // Client: Now, let's rollback!
  // Caretaker: Restoring state to Sun Jul 18 14:59:22 2021
  //  / (J62BwigpK...)
  // Originator: My state has changed to: J62BwigpKoATo4ecAg9RKs7X1yyg6V.
  //
  // Client: Once more!
  // Caretaker: Restoring state to Sun Jul 18 14:59:22 2021
  //  / (ZytqiXve7...)
  // Originator: My state has changed to: ZytqiXve7N92uBo84YJdlgF9tRh9Y3.

  return 0;
}
