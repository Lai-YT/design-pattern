from abc import ABC, abstractmethod
from overrides import overrides

from product import *


class Factory(ABC):
    @abstractmethod
    def get_product(self, state: str) -> Product:
        pass


class FrenchFriesFactory(Factory):
    @overrides
    def get_product(self, state: str = 'salty') -> Product:
        return FrenchFries(state)
