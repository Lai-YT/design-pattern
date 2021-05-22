from __future__ import annotations
from abc import ABC, abstractmethod
from overrides import overrides

from subject import *


class Observer(ABC):
    """
    The Observer interface declares the update method, used by subjects.
    """

    @abstractmethod
    def update(self, subject: Subject) -> None:
        """
        Receive update from subject.
        """
        pass


"""
Concrete Observers react to the updates issued by the Subject they had been
attached to.
"""
class ConcreteObserverA(Observer):
    @overrides
    def update(self, subject: Subject) -> None:
        if subject.state < 3:
            print('ConcreteObserverA: Reacted to the event.')


class ConcreteObserverB(Observer):
    @overrides
    def update(self, subject: Subject) -> None:
        if subject.state == 0 or subject.state >= 2:
            print('ConcreteObserverB: Reacted to the event.')
