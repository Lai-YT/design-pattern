from overrides import overrides

from order import *


class Item(Order):
    def __init__(self) -> None:
        self._order: Order = None

    def decorate(self, order: Order) -> None:
        self._order = order

    @overrides
    def show(self) -> None:
        if self._order:
            self._order.show()


class Drink(Item):
    @overrides
    def show(self) -> None:
        super().show()
        self._add_drink()

    def _add_drink(self) -> None:
        print('--> drink')


class Salad(Item):
    @overrides
    def show(self) -> None:
        super().show()
        self._add_salad()

    def _add_salad(self) -> None:
        print('--> salad')


class Soup(Item):
    @overrides
    def show(self) -> None:
        super().show()
        self._add_soup()

    def _add_soup(self) -> None:
        print('--> soup')


class MainMeal(Item):
    @overrides
    def show(self) -> None:
        super().show()
        self._add_main_meal()

    def _add_main_meal(self) -> None:
        print('--> main meal')
