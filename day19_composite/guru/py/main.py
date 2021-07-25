from component import *


def client_code_1(component: Component) -> None:
    """
    The client code works with all of the components via the base interface.
    """

    print(f'Result: {component.operation()}.')


def client_code_2(component_1: Component, component_2: Component) -> None:
    """
    Thanks to the fact that the child-management operations are declared in the
    base Component class, the client code can work with any component, simple or
    complex, without depending on their concrete classes.
    """

    if component_1.is_composite():
        component_1.add(component_2)

    print(f'Result: {component_1.operation()}.')


if __name__ == '__main__':
    # This way the client code can support the simple leaf components...
    simple = Leaf()
    print('Client: I\'ve got a simple component.')
    client_code_1(simple)
    print()

    # ...as well as the complex composites.
    tree = Composite()

    branch_1 = Composite()
    branch_1.add(Leaf())
    branch_1.add(Leaf())

    branch_2 = Composite()
    branch_2.add(Leaf())

    tree.add(branch_1)
    tree.add(branch_2)
    print('Client: Now I\'ve got a composite tree.')
    client_code_1(tree)
    print()

    print('Client: I don\'t need to check the components classes even when managing the tree.')
    client_code_2(tree, simple)
    # Client: I've got a simple component.
    # Result: Leaf.
    #
    # Client: Now I've got a composite tree.
    # Result: Branch(Branch(Leaf+Leaf)+Branch(Leaf)).
    #
    # Client: I don't need to check the components classes even when managing the tree.
    # Result: Branch(Branch(Leaf+Leaf)+Branch(Leaf)+Leaf).
