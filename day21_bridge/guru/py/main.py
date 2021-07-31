from abstraction import *
from implementation import *


def client_code(abstraction: Abstraction) -> None:
    """
    Except for the initialization phase, where an Abstraction object gets linked
    with a specific Implementation object, the client code should only depend on
    the Abstraction class. This way the client code can support any abstraction-
    implementation combination.
    """

    # ...
    print(abstraction.operation())
    # ...


if __name__ == '__main__':
    """
    The client code should be able to work with any pre-configured abstraction-
    implementation combination.
    """

    implementation_a = ConcreteImplementationA()
    abstraction = Abstraction(implementation_a)
    client_code(abstraction)
    print()

    implementation_b = ConcreteImplementationB()
    extended_abstraction = ExtendedAbstraction(implementation_b)
    client_code(extended_abstraction)
    # Abstraction: Base operation with
    # ConcreteImplementationA: Here's the result on the platform A.
    #
    # ExtendedAbstraction: Extended operation with
    # ConcreteImplementationB: Here's the result on the platform B.
