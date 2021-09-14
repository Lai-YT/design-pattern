from overrides import overrides

from item import *
from order import *


class Set(Order):
    def __init__(self) -> None:
        self._order: Order = None

    def decorate(self, order: Order) -> None:
        self._order = order

    @overrides
    def show(self) -> None:
        if self._order:
            self._order.show()


class SimpleSet(Set):
    @overrides
    def show(self) -> None:
        self._add_set()
        super().show()

    def _add_set(self) -> None:
        salad = Salad();
        main_meal = MainMeal()
        main_meal.decorate(salad)

        drink = Drink()
        drink.decorate(main_meal)

        super().decorate(drink)
