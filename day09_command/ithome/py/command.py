from abc import ABC, abstractmethod
from overrides import overrides

from light import Light


class Command(ABC):
    def __init__(self, light: Light) -> None:
        self._light = light

    @abstractmethod
    def execute(self) -> None:
        pass


class TurnOn(Command):
    @overrides
    def execute(self) -> None:
        self._light.turn_on()

class TurnOff(Command):
    @overrides
    def execute(self) -> None:
        self._light.turn_off()

class Brighten(Command):
    @overrides
    def execute(self) -> None:
        self._light.brighten()

class Darken(Command):
    @overrides
    def execute(self) -> None:
        self._light.darken()
