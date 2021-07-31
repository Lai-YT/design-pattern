from abc import ABC, abstractmethod
from overrides import overrides


class Implementation:
    """
    The Implementation defines the interface for all implementation classes. It
    doesn't have to match the Abstraction's interface. In fact, the two
    interfaces can be entirely different. Typically the Implementation interface
    provides only primitive operations, while the Abstraction defines higher-
    level operations based on those primitives.
    """

    @abstractmethod
    def operation_implementation(self) -> str:
        pass


"""
Each Concrete Implementation corresponds to a specific platform and implements
the Implementation interface using that platform's API.
"""
class ConcreteImplementationA(Implementation):
    @overrides
    def operation_implementation(self) -> str:
        return 'ConcreteImplementationA: Here\'s the result on the platform A.'


class ConcreteImplementationB(Implementation):
    @overrides
    def operation_implementation(self) -> str:
        return 'ConcreteImplementationB: Here\'s the result on the platform B.'
