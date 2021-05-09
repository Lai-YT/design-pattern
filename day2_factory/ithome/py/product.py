from abc import ABC, abstractmethod
from overrides import overrides


class Product(ABC):
    @abstractmethod
    def describe(self) -> None:
        pass


class FrenchFries(Product):
    def __init__(self, state: str) -> None:
        self._state = state

    @overrides
    def describe(self) -> None:
        print('I\'m', self._state, 'french fries')
