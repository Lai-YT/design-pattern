#ifndef SUBSYSTEN_HPP_
#define SUBSYSTEN_HPP_

#include <string>

// The Subsystem can accept requests either from the facade or client directly.
// In any case, to the Subsystem, the Facade is yet another client, and it's not
// a part of the Subsystem.
class Subsystem1 {
public:
  std::string Operation1() const {
    return "Subsystem1: Ready!\n";
  }

  // ...

  std::string OperationN() const {
    return "Subsystem1: Go!\n";
  }
};


 // Some facades can work with multiple subsystems at the same time.
 class Subsystem2 {
 public:
   std::string Operation1() const {
     return "Subsystem2: Get ready!\n";
   }

   // ...

   std::string OperationZ() const {
     return "Subsystem2: Fire!\n";
   }
 };


#endif /* end of include guard: SUBSYSTEN_HPP_ */
