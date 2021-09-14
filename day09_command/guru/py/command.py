from abc import ABC, abstractmethod
from overrides import overrides

from receiver import *


class Command(ABC):
    """
    The Command interface declares a method for executing a command.
    """

    @abstractmethod
    def execute(self) -> None:
        pass


class SimpleCommand(Command):
    """
    Some commands can implement simple operations on their own.
    """

    def __init__(self, payload: str) -> None:
        self._payload = payload

    @overrides
    def execute(self) -> None:
        print(f'SimpleCommand: See, I can do simple things like printing ({self._payload})')


class ComplexCommand(Command):
    """
    However, some commands can delegate more complex operations to other
    objects, called "receivers."
    """

    def __init__(self, receiver: Receiver, a: str, b: str) -> None:
        """
        Complex commands can accept one or several receiver objects along with
        any context data via the constructor.
        """

        self._receiver = receiver
        self._a = a
        self._b = b

    @overrides
    def execute(self) -> None:
        """
        Commands can delegate to any methods of a receiver.
        """

        print('ComplexCommand: Complex stuff should be done by a receiver object.')
        self._receiver.do_something(self._a)
        self._receiver.do_something_else(self._b)
