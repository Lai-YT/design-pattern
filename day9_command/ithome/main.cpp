#include "command.hpp"
#include "invoker.hpp"
#include "light.hpp"

int main(int argc, char const *argv[]) {

  Light* light = new Light;
  Invoker* invoker = new Invoker;

  invoker->SetCommand(new TurnOn(light));
  invoker->Execute();

  invoker->SetCommand(new Brighten(light));
  invoker->Execute();

  invoker->SetCommand(new Darken(light));
  invoker->Execute();

  invoker->SetCommand(new TurnOff(light));
  invoker->Execute();

  invoker->Undo();
  invoker->Undo();
  invoker->Undo();
  // Waiting for execution...
  // Do: Light is turned on
  // Waiting for execution...
  // Do: Light is brightened
  // Waiting for execution...
  // Do: Light is darkened
  // Waiting for execution...
  // Do: Light is turned off
  // Execute the previous command...
  // Do: Light is darkened
  // Execute the previous command...
  // Do: Light is brightened
  // Execute the previous command...
  // Do: Light is turned on

  delete invoker;
  delete light;

  return 0;
}
