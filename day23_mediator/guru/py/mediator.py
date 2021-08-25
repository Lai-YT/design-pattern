from __future__ import annotations
from abc import ABC, abstractmethod
from overrides import overrides
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from component import BaseComponent, Component1, Component2


class Mediator(ABC):
    """
    The Mediator interface declares a method used by components to notify the
    mediator about various events. The Mediator may react to these events and
    pass the execution to other components.
    """

    @abstractmethod
    def notify(self, sender: BaseComponent, event: str) -> None:
        pass


class ConcreteMediator(Mediator):
    def __init__(self, component_1: Component1, component_2: Component2) -> None:
        self._component_1 = component_1
        self._component_1.mediator = self
        self._component_2 = component_2
        self._component_2.mediator = self

    @overrides
    def notify(self, sender: BaseComponent, event: str) -> None:
        if event == 'A':
            print('Mediator reacts on A and triggers following operations:')
            self._component_2.do_c()
        elif event == 'D':
            print('Mediator reacts on D and triggers following operations:')
            self._component_1.do_b()
            self._component_2.do_c()
