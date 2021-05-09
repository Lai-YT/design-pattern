from abc import ABC, abstractmethod
from overrides import overrides


class Product(ABC):
    """
    The Product interface declares the operations that all concrete products
    must implement.
    """

    @abstractmethod
    def operation(self) -> str:
        pass


"""
Concrete Products provide various implementations of the Product interface.
"""
class ConcreteProduct1(Product):
    @overrides
    def operation(self) -> str:
        return '{Result of the ConcreteProduct1}'


class ConcreteProduct2(Product):
    @overrides
    def operation(self) -> str:
        return '{Result of the ConcreteProduct2}'
