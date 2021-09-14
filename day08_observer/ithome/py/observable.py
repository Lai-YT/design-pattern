from __future__ import annotations
from abc import ABC, abstractmethod
from overrides import overrides
from typing import List

from observer import IObserver


class IObservable(ABC):
    @abstractmethod
    def add(self, observer: IObserver) -> None:
        pass

    @abstractmethod
    def notify(self) -> None:
        pass

    @property
    @abstractmethod
    def name(self) -> str:
        pass


class Podcast(IObservable):
    def __init__(self, name: str) -> None:
        self._name = name
        self._observers: List[IObserver] = list()

    @overrides
    def add(self, observer: IObserver) -> None:
        self._observers.append(observer)

    @overrides
    def notify(self) -> None:
        for observer in self._observers:
            observer.update()

    @property
    def name(self) -> str:
        return self._name

    @name.setter
    def name(self, name: str) -> None:
        self._name = name
