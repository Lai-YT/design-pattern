from abc import ABC, abstractmethod
from datetime import datetime


class Memento(ABC):
    """
    The Memento interface provides a way to retrieve the memento's metadata,
    such as creation date or name. However, it doesn't expose the Originator's
    state.
    """

    @property
    @abstractmethod
    def name(self) ->str:
        pass

    @property
    @abstractmethod
    def date(self) -> str:
        pass


class ConcreteMemento(Memento):
    def __init__(self, state: str) -> None:
        self._state = state
        self._date = str(datetime.now())[:19]

    # Since this is a public method, state risks the exposure.
    def get_state(self) -> str:
        """
        The Originator uses this method when restoring its state.
        """

    """
    The rest of the methods are used by the Caretaker to display metadata.
    """
    @property
    def name(self) -> str:
        return f'{self._date} / ({self._state[:9]}...)'

    @property
    def date(self) -> str:
        return self._date
