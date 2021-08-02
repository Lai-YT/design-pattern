#include "command.hpp"
#include "invoker.hpp"
#include "light.hpp"


int main(int argc, char const *argv[]) {
  Light light;
  Invoker invoker;

  invoker.SetCommand(TurnOn(light));
  invoker.Execute();

  invoker.SetCommand(Brighten(light));
  invoker.Execute();

  invoker.SetCommand(Darken(light));
  invoker.Execute();

  invoker.SetCommand(TurnOff(light));
  invoker.Execute();

  invoker.Undo();
  invoker.Undo();
  invoker.Undo();
  // Waiting for execution...
  // Do: Light is turned on.
  // Waiting for execution...
  // Do: Light is brightened.
  // Waiting for execution...
  // Do: Light is darkened.
  // Waiting for execution...
  // Do: Light is turned off.
  // Execute the previous command...
  // Do: Light is darkened.
  // Execute the previous command...
  // Do: Light is brightened.
  // Execute the previous command...
  // Do: Light is turned on.

  return 0;
}
