from __future__ import annotations
from typing import Optional

from mediator import *


class BaseComponent:
    """
    The Base Component provides the basic functionality of storing a mediator's
    instance inside component objects.
    """

    def __init__(self, mediator: Optional[Mediator] = None) -> None:
        self._mediator = mediator

    @property
    def mediator(self) -> Optional[Mediator]:
        return self._mediator

    @mediator.setter
    def mediator(self, mediator: Mediator) -> None:
        self._mediator = mediator


"""
Concrete Components implement various functionality. They don't depend on other
components. They also don't depend on any concrete mediator classes.
"""

class Component1(BaseComponent):
    def do_a(self) -> None:
        print('Component1 does A.')
        if self._mediator is not None:
            self._mediator.notify(self, 'A')

    def do_b(self) -> None:
        print('Component1 does B.')
        if self._mediator is not None:
            self._mediator.notify(self, 'B')


class Component2(BaseComponent):
    def do_c(self) -> None:
        print('Component2 does C.')
        if self._mediator is not None:
            self._mediator.notify(self, 'C')

    def do_d(self) -> None:
        print('Component2 does D.')
        if self._mediator is not None:
            self._mediator.notify(self, 'D')
