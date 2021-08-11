from __future__ import annotations
from abc import ABC, abstractmethod
from overrides import overrides
from typing import Any, Optional


class Handler(ABC):
    """
    The Handler interface declares a method for building the chain of handlers.
    It also declares a method for executing a request.
    """

    @abstractmethod
    def set_next(self, handler: Handler) -> Handler:
        pass

    @abstractmethod
    def handle(self, request: Any) -> Optional[str]:
        pass


class AbstractHandler(Handler):
    """
    The default chaining behavior can be implemented inside a base handler
    class.
    """

    def __init__(self) -> None:
        self._next_handler: Optional[Handler] = None

    @overrides
    def set_next(self, handler: Handler) -> Handler:
        self._next_handler = handler
        # Returning a handler from here will let us link handlers in a
        # convenient way like this:
        # monkey.set_next(squirrel).set_next(dog)
        return handler

    @abstractmethod
    def handle(self, request: Any) -> Optional[str]:
        if self._next_handler is None:
            return None
        return self._next_handler.handle(request)


"""
All Concrete Handlers either handle a request or pass it to the next handler in
the chain.
"""

class MonkeyHandler(AbstractHandler):
    @overrides
    def handle(self, request: Any) -> Optional[str]:
        if request == 'Banana':
            return f'Monkey: I\'ll eat the {request}.'
        else:
            return super().handle(request)


class SquirrelHandler(AbstractHandler):
    @overrides
    def handle(self, request: Any) -> Optional[str]:
        if request == 'Nut':
            return f'Squirrel: I\'ll eat the {request}.'
        else:
            return super().handle(request)


class DogHandler(AbstractHandler):
    @overrides
    def handle(self, request: Any) -> Optional[str]:
        if request == 'MeatBall':
            return f'Dog: I\'ll eat the {request}.'
        else:
            return super().handle(request)
