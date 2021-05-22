from __future__ import annotations
from abc import ABC, abstractmethod
from overrides import overrides

from observable import *


class IObserver(ABC):
    @abstractmethod
    def update(self) -> None:
        pass


class Student(IObserver):
    def __init__(self, observable: IObservable) -> None:
        self._observable = observable
        # also add self observer into observable's list
        self._observable.add(self)

    @overrides
    def update(self) -> None:
        print(f'heard {self._observable.name}')
