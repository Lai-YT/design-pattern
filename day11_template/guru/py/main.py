from abstract import *
from concrete import *


def client_code(abstract_class: AbstractClass) -> None:
    """
    The client code calls the template method to execute the algorithm. Client
    code does not have to know the concrete class of an object it works with, as
    long as it works with objects through the interface of their base class.
    """

    abstract_class.template_method()


if __name__ == '__main__':
    print('Same client code can work with different subclasses:')
    client_code(ConcreteClass1())

    print()

    print('Same client code can work with different subclasses:')
    client_code(ConcreteClass2())
    # Same client code can work with different subclasses:
    # AbstractClass says: I am doing the bulk of the work.
    # ConcreteClass1 says: Implemented operation_1.
    # AbstractClass says: But I let subclasses override some operations.
    # ConcreteClass1 says: Implemented operation_2.
    # AbstractClass says: But I am doing the bulk of the work anyway.
    #
    # Same client code can work with different subclasses:
    # AbstractClass says: I am doing the bulk of the work.
    # ConcreteClass2 says: Implemented operation_1.
    # AbstractClass says: But I let subclasses override some operations.
    # ConcreteClass2 says: Overridden hook_1.
    # ConcreteClass2 says: Implemented operation_2.
    # AbstractClass says: But I am doing the bulk of the work anyway.
