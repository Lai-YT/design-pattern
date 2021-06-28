from overrides import overrides

from abstract import *


class ConcreteClass1(AbstractClass):
    """
    Concrete classes have to implement all abstract operations of the base
    class. They can also override some operations with a default implementation.
    """

    @overrides
    def required_operation_1(self) -> None:
        print('ConcreteClass1 says: Implemented operation_1.')

    @overrides
    def required_operation_2(self) -> None:
        print('ConcreteClass1 says: Implemented operation_2.')


class ConcreteClass2(AbstractClass):
    """
    Usually, concrete classes override only a fraction of base class'
    operations.
    """

    @overrides
    def required_operation_1(self) -> None:
        print('ConcreteClass2 says: Implemented operation_1.')

    @overrides
    def required_operation_2(self) -> None:
        print('ConcreteClass2 says: Implemented operation_2.')

    @overrides
    def hook_1(self) -> None:
        print('ConcreteClass2 says: Overridden hook_1.')
