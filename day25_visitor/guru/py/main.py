from typing import List

from component import Component, ConcreteComponentA, ConcreteComponentB
from visitor import Visitor, ConcreteVisitor1, ConcreteVisitor2


def client_code(components: List[Component], visitor: Visitor) -> None:
    """
    The client code can run visitor operations over any set of elements without
    figuring out their concrete classes. The accept operation directs a call to
    the appropriate operation in the visitor object.
    """

    # ...
    for component in components:
        component.accept(visitor)
    # ...


if __name__ == '__main__':
    components: List[Component] = [ConcreteComponentA(), ConcreteComponentB()]

    print('The client code works with all visitors via the base Visitor interface:')
    visitor_1 = ConcreteVisitor1()
    client_code(components, visitor_1)

    print('It allows the same client code to work with different types of visitors:')
    visitor_2 = ConcreteVisitor2()
    client_code(components, visitor_2)
    # The client code works with all visitors via the base Visitor interface:
    # A + ConcreteVisitor1
    # B + ConcreteVisitor1
    # It allows the same client code to work with different types of visitors:
    # A + ConcreteVisitor2
    # B + ConcreteVisitor2
