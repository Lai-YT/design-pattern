from facade import *
from subsystem import *


def client_code(facade: Facade) -> None:
    """
    The client code works with complex subsystems through a simple interface
    provided by the Facade. When a facade manages the lifecycle of the
    subsystem, the client might not even know about the existence of the
    subsystem. This approach lets you keep the complexity under control.
    """

    print(facade.operation(), end='')


if __name__ == '__main__':
    # The client code may have some of the subsystem's objects already created.
    # In this case, it might be worthwhile to initialize the Facade with these
    # objects instead of letting the Facade create new instances.
    subsystem_1 = Subsystem1()
    subsystem_2 = Subsystem2()
    facade = Facade(subsystem_1, subsystem_2)
    client_code(facade)
    # Facade initializes subsystems.
    # Subsystem1: Ready!
    # Subsystem2: Get ready!
    # Facade orders subsystems to perform the action.
    # Subsystem1: Go!
    # Subsystem2: Fire!
