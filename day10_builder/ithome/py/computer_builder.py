from __future__ import annotations
from abc import ABC, abstractmethod
from overrides import overrides

from computer_part import *
from computer import *


class ComputerBuilder:
    def __init__(self) -> None:
        self._computer = Computer()

    @abstractmethod
    def build_processor(self, processor: Processor) -> ComputerBuilder:
        pass

    @abstractmethod
    def build_memory(self, memory: Memory) -> ComputerBuilder:
        pass

    @abstractmethod
    def build_graphics(self, graphics: Graphics) -> ComputerBuilder:
        pass

    @abstractmethod
    def build_storage(self, storage: Storage) -> ComputerBuilder:
        pass

    def deliver(self) -> Computer:
        computer: Computer = self._computer
        self._computer = Computer()
        print('End building. Deliver the computer.')
        return computer


class ConcreteComputerBuilder(ComputerBuilder):
    @overrides
    def build_processor(self, processor: Processor) -> ConcreteComputerBuilder:
        self._computer.set_processor(processor)
        return self

    @overrides
    def build_memory(self, memory: Memory) -> ConcreteComputerBuilder:
        self._computer.set_memory(memory)
        return self

    @overrides
    def build_graphics(self, graphics: Graphics) -> ConcreteComputerBuilder:
        self._computer.set_graphics(graphics)
        return self

    @overrides
    def build_storage(self, storage: Storage) -> ConcreteComputerBuilder:
        self._computer.set_storage(storage)
        return self
