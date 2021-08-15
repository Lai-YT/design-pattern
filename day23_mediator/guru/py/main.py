from component import Component1, Component2
from mediator import ConcreteMediator


def client_code() -> None:
    c1 = Component1()
    c2 = Component2()
    mediator = ConcreteMediator(c1, c2)

    print('Client triggers operation A.')
    c1.do_a()
    print()

    print('Client triggers operation D.')
    c2.do_d()


if __name__ == '__main__':
    client_code()
    # Client triggers operation A.
    # Component1 does A.
    # Mediator reacts on A and triggers following operations:
    # Component2 does C.
    #
    # Client triggers operation D.
    # Component2 does D.
    # Mediator reacts on D and triggers following operations:
    # Component1 does B.
    # Component2 does C.
