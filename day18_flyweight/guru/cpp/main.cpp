#include <iostream>
#include <string>

#include "flyweight.hpp"
#include "state.hpp"


void AddCarToPoliceDatabase(FlyweightFactory& ff, const std::string& plates,
                            const std::string& owner, const std::string& brand,
                            const std::string& model, const std::string& color) {
  std::cout << "Client: Adding a car to database." << '\n';
  const Flyweight& flyweight = ff.GetFlyweight({brand, model, color});
  // The client code either stores or calculates extrinsic state and passes it
  // to the flyweight's methods.
  flyweight.Operation({owner, plates});
}


// The client code usually creates a bunch of pre-populated flyweights in the
// initialization stage of the application.
int main(int argc, char const *argv[]) {
  FlyweightFactory factory({
    {"Chevrolet", "Camaro2018", "pink"},
    {"Mercedes Benz", "C300", "black"}, {"Mercedes Benz", "C500", "red"},
    {"BMW", "M5", "red"}, {"BMW", "X6", "white"}
  });
  factory.ListFlyweights();
  std::cout << '\n';

  AddCarToPoliceDatabase(factory, "CL234IR", "James Doe", "BMW", "M5", "red");
  std::cout << '\n';
  AddCarToPoliceDatabase(factory, "CL234IR", "James Doe", "BMW", "X1", "red");
  std::cout << '\n';
  
  factory.ListFlyweights();
  // FlyweightFactory: I have 5 flyweights.
  // BMW_M5_red
  // Mercedes Benz_C500_red
  // Mercedes Benz_C300_black
  // BMW_X6_white
  // Chevrolet_Camaro2018_pink
  //
  // Client: Adding a car to database.
  // FlyweightFactory: Reuse the existing flyweight.
  // Flyweight: Displaying shared ([ BMW, M5, red ]) and unique ([ James Doe, CL234IR ]) state.
  //
  // Client: Adding a car to database.
  // FlyweightFactory: Can't find the flyweight. Create a new one.
  // Flyweight: Displaying shared ([ James Doe, CL234IR, red ]) and unique ([ James Doe, CL234IR ]) state.
  //
  // FlyweightFactory: I have 6 flyweights.
  // BMW_M5_red
  // Mercedes Benz_C500_red
  // Mercedes Benz_C300_black
  // BMW_X1_red
  // BMW_X6_white
  // Chevrolet_Camaro2018_pink

  return 0;
}
