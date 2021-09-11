from abc import ABC, abstractmethod
from enum import Enum
from overrides import overrides


class SugarType(Enum):
    REGULAR = 'regular'
    LESS    = 'less'
    HALF    = 'half'
    QUARTER = 'quarter'
    FREE    = 'free'


class IceType(Enum):
    REGULAR = 'regular'
    EASY    = 'easy'
    FREE    = 'free'
    HOT     = 'hot'


class Drink(ABC):
    def __init__(self, sugar: SugarType, ice: IceType) -> None:
        self._sugar = sugar
        self._ice = ice

    @property
    def sugar(self) -> SugarType:
        return self._sugar

    @property
    def ice(self) -> IceType:
        return self._ice

    @abstractmethod
    def describe(self) -> None:
        print(f'Sweetness level: {self._sugar.value}')
        print(f'Amount of ice: {self._ice.value}')


class TeaType(Enum):
    BLACK  = 'black'
    GREEN  = 'green'
    OOLONG = 'oolong'


class Tea(Drink):
    def __init__(self, tea: TeaType, sugar: SugarType, ice: IceType) -> None:
        super().__init__(sugar, ice)
        self._tea = tea

    @property
    def tea(self) -> TeaType:
        return self._tea

    @overrides
    def describe(self) -> None:
        print(f'It\'s a cup of {self._tea.value} tea.')
        super().describe()


class CoffeeType(Enum):
    LATTE     = 'latte'
    AMERICANO = 'Americano'
    ESPRESSO  = 'espresso'


class Coffee(Drink):
    def __init__(self, coffee: CoffeeType, sugar: SugarType, ice: IceType) -> None:
        super().__init__(sugar, ice)
        self._coffee = coffee

    @property
    def coffee(self) -> CoffeeType:
        return self._coffee

    @overrides
    def describe(self) -> None:
        print(f'It\'s a cup of {self._coffee.value}.')
        super().describe()
