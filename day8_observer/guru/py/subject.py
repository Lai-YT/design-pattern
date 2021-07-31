from __future__ import annotations
from abc import ABC, abstractmethod
from overrides import overrides
from random import randrange
from typing import List, Optional

from observer import *


class Subject(ABC):
    """
    The Subject interface declares a set of methods for managing subscribers.
    """

    @abstractmethod
    def attach(self, observer: Observer) -> None:
        """
        Attach an observer to the subject.
        """
        pass

    @abstractmethod
    def detach(self, observer: Observer) -> None:
        """
        Detach an observer from the subject.
        """
        pass

    @abstractmethod
    def notify(self) -> None:
        """
        Notify all observers about an event.
        """
        pass

    @property
    @abstractmethod
    def state(self) -> Optional[int]:
        pass


class ConcreteSubject(Subject):
    """
    The Subject owns some important state and notifies observers when the state
    changes.
    """

    def __init__(self) -> None:
        self._state: Optional[int] = None
        """
        For the sake of simplicity, the Subject's state, essential to all
        subscribers, is stored in this variable.
        """

        self._observers: List[Observer] = list()
        """
        List of subscribers. In real life, the list of subscribers can be stored
        more comprehensively (categorized by event type, etc.).
        """

    """
    The subscription management methods.
    """
    @overrides
    def attach(self, observer: Observer) -> None:
        print('Subject: Attached an observer.')
        self._observers.append(observer)

    @overrides
    def detach(self, observer: Observer) -> None:
        self._observers.remove(observer)

    @overrides
    def notify(self) -> None:
        """
        Trigger an update in each subscriber.
        """

        print('Subject: Notifying observers...')
        for observer in self._observers:
            observer.update(self)

    @property
    def state(self) -> Optional[int]:
        return self._state

    def some_business_logic(self) -> None:
        """
        Usually, the subscription logic is only a fraction of what a Subject can
        really do. Subjects commonly hold some important business logic, that
        triggers a notification method whenever something important is about to
        happen (or after it).
        """

        print('Subject: I\'m doing something important.')

        self._state = randrange(0, 10)
        print(f'Subject: My state has just changed to {self._state}.')

        self.notify()
