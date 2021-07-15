from context import Context
from state import *


def client_code() -> None:
    context = Context(ConcreteStateA())
    context.request_1()
    context.request_2()


if __name__ == '__main__':
    client_code()
    # Context: Transition to ConcreteStateA
    # ConcreteStateA handles request_1.
    # ConcreteStateA wants to change the state of the context.
    # Context: Transition to ConcreteStateB
    # ConcreteStateB handles request_2.
    # ConcreteStateB wants to change the state of the context.
    # Context: Transition to ConcreteStateA
