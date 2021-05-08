from abc import ABC, abstractmethod
from overrides import overrides


class Strategy(ABC):
    @abstractmethod
    def calculate(self, a: int, b: int) -> int:
        pass


class Add(Strategy):
    @overrides
    def calculate(self, a: int, b: int) -> int:
        return a + b


class Minus(Strategy):
    @overrides
    def calculate(self, a: int, b: int) -> int:
        return a - b


class Multiply(Strategy):
    @overrides
    def calculate(self, a: int, b: int) -> int:
        return a * b


class Divide(Strategy):
    @overrides
    def calculate(self, a: int, b: int) -> int:
        return a // b
