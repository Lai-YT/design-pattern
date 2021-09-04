from abc import ABC, abstractmethod
from overrides import overrides
from typing import List


class Strategy(ABC):
    """
    The Strategy interface declares operations common to all supported versions
    of some algorithm.

    The Context uses this interface to call the algorithm defined by Concrete
    Strategies.
    """

    @abstractmethod
    def do_algorithm(self, data: List) -> List:
        pass


"""
Concrete Strategies implement the algorithm while following the base Strategy
interface. The interface makes them interchangeable in the Context.
"""

class ConcreteStrategyA(Strategy):
    @overrides
    def do_algorithm(self, data: List) -> List:
        """
        normal sorting
        """
        return sorted(data)


class ConcreteStrategyB(Strategy):
    @overrides
    def do_algorithm(self, data: List) -> List:
        """
        reverse sorting
        """
        return sorted(data, reverse=True)
