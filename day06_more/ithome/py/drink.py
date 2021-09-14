from abc import ABC


class Drink(ABC):
    def __init__(self, price: int) -> None:
        self._price = price

    @property
    def price(self) -> int:
        return self._price


class MilkTea(Drink):
    def __init__(self, price: int) -> None:
        super().__init__(price)


class Coffee(Drink):
    def __init__(self, price: int) -> None:
        super().__init__(price)
