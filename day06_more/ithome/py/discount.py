from abc import ABC, abstractmethod
from math import floor
from overrides import overrides
from typing import Union


class DiscountStrategy(ABC):
    def __init__(self, discount: Union[int, float]) -> None:
        self._discount = discount

    @abstractmethod
    def get_price(price: int) -> int:
        pass


class NoDiscount(DiscountStrategy):
    def __init__(self) -> None:
        super().__init__(0)

    def get_price(self, price: int) -> int:
        return price


class MinusDiscount(DiscountStrategy):
    def __init__(self, discount: int) -> None:
        super().__init__(discount)

    @overrides
    def get_price(self, price: int) -> int:
        # can add error detection for discount > price
        return price - self._discount


class MultiplyDiscount(DiscountStrategy):
    def __init__(self, discount: float) -> None:
        # can add error detection for discount > 1
        super().__init__(discount)

    @overrides
    def get_price(self, price: int) -> int:
        return floor(price * self._discount)
