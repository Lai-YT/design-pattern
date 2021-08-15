#include <iostream>
#include <string>

#include "component.hpp"
#include "mediator.hpp"


void ConcreteMediator::Notify(const BaseComponent* const sender, const std::string& event) const {
  if (event == "A") {
    std::cout << "Mediator reacts on A and triggers following operations:" << '\n';
    component_2_->DoC();
  } else if (event == "D") {
    std::cout << "Mediator reacts on D and triggers following operations:" << '\n';
    component_1_->DoB();
    component_2_->DoC();
  }
}

ConcreteMediator::ConcreteMediator(Component1* const component_1, Component2* const component_2)
  :component_1_(component_1),component_2_(component_2) {
  component_1_->SetMediator(this);
  component_2_->SetMediator(this);
}
