from component import *
from decorator import *


def client_code(component: Component) -> None:
    """
    The client code works with all objects using the Component interface. This
    way it can stay independent of the concrete classes of components it works
    with.
    """

    print(f'Result: {component.operation()}')


if __name__ == '__main__':
    # This way the client code can support both simple components...
    simple = ConcreteComponent()
    print('Client: I\'ve got a simple component:')
    client_code(simple)

    print()

    # ...as well as decorated ones.
    #
    # Note how decorators can wrap not only simple components but the other
    # decorators as well.
    decorator1 = ConcreteDecoratorA(simple)
    decorator2 = ConcreteDecoratorB(decorator1)
    print('Client: Now I\'ve got a decorated component:')
    client_code(decorator2)
    # Client: I've got a simple component:
    # Result: ConcreteComponent
    #
    # Client: Now I've got a decorated component:
    # Result: ConcreteDecoratorB(ConcreteDecoratorA(ConcreteComponent))
