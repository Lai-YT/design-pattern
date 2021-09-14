from typing import List

from discount import *
from drink import *


# The whole group of drinks use the same discount strategy.
class DrinkOrder:
    def __init__(self, discount_strategy: DiscountStrategy) -> None:
        self._discount_strategy = discount_strategy
        self._order_list: List[Drink] = []

    def change_discount(self, discount_strategy: DiscountStrategy) -> None:
        """
        You are allowed to change the strategy of discount in the middle of order.
        """
        self._discount_strategy = discount_strategy

    def order(self, drink: Drink) -> None:
        print(f'Order: A {drink.price}-dollar drink.')
        self._order_list.append(drink)

    def get_total_price(self) -> int:
        total_price: int = 0
        for drink in self._order_list:
            total_price += self._discount_strategy.get_price(drink.price)

        return total_price
