from __future__ import annotations
from abc import ABC, abstractmethod
from overrides import overrides

import context as c


class State(ABC):
    """
    The base State class declares methods that all Concrete State should
    implement and also provides a backreference to the Context object,
    associated with the State. This backreference can be used by States to
    transition the Context to another State.
    """

    @property
    def context(self) -> c.Context:
        return self._context

    @context.setter
    def context(self, context: c.Context) -> None:
        self._context = context

    @abstractmethod
    def handle_1(self) -> None:
        pass

    @abstractmethod
    def handle_2(self) -> None:
        pass


"""
Concrete States implement various behaviors, associated with a state of the
Context.
"""
class ConcreteStateA(State):
    @overrides
    def handle_1(self) -> None:
        print('ConcreteStateA handles request_1.')
        print('ConcreteStateA wants to change the state of the context.')
        self._context.transition_to(ConcreteStateB())

    @overrides
    def handle_2(self) -> None:
        print('ConcreteStateA handles request_2.')


class ConcreteStateB(State):
    @overrides
    def handle_1(self) -> None:
        print('ConcreteStateB handles request_1.')

    @overrides
    def handle_2(self) -> None:
        print('ConcreteStateB handles request_2.')
        print('ConcreteStateB wants to change the state of the context.')
        self._context.transition_to(ConcreteStateA())
