#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include "light.hpp"


class Command {
public:
  Command(Light& light)
    :light_(light) {}

  virtual ~Command() = default;

  virtual void Execute() = 0;

  virtual Command* Clone() const = 0;

protected:
  Light& light_;
};


class TurnOn : public Command {
public:
  explicit TurnOn(Light& light)
    :Command(light) {}

  void Execute() override {
    light_.TurnOn();
  }

  TurnOn* Clone() const override {
    return new TurnOn(*this);
  }
};

class TurnOff : public Command {
public:
  explicit TurnOff(Light& light)
    :Command(light) {}

  void Execute() override {
    light_.TurnOff();
  }

  TurnOff* Clone() const override {
    return new TurnOff(*this);
  }
};

class Brighten : public Command {
public:
  explicit Brighten(Light& light)
    :Command(light) {}

  void Execute() override {
    light_.Brighten();
  }

  Brighten* Clone() const override {
    return new Brighten(*this);
  }
};

class Darken : public Command {
public:
  explicit Darken(Light& light)
    :Command(light) {}

  void Execute() override {
    light_.Darken();
  }

  Darken* Clone() const override {
    return new Darken(*this);
  }
};


#endif /* end of include guard: COMMAND_HPP_ */
