#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include "light.hpp"

class Command {
public:
  Command(Light* light)
    :light_(light) {}

  virtual ~Command() = default;

  virtual void Execute() = 0;

protected:
  Light* light_ = nullptr;
};

class TurnOn : public Command {
public:
  explicit TurnOn(Light* light)
    :Command(light) {}

  void Execute() override {
    light_->TurnOn();
  }
};

class TurnOff : public Command {
public:
  explicit TurnOff(Light* light)
    :Command(light) {}

  void Execute() override {
    light_->TurnOff();
  }
};

class Brighten : public Command {
public:
  explicit Brighten(Light* light)
    :Command(light) {}

  void Execute() override {
    light_->Brighten();
  }
};

class Darken : public Command {
public:
  explicit Darken(Light* light)
    :Command(light) {}

  void Execute() override {
    light_->Darken();
  }
};

#endif /* end of include guard: COMMAND_HPP_ */
