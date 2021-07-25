from __future__ import annotations
from datetime import datetime
from random import sample
from string import ascii_letters


class Originator:
    """
    The Originator holds some important state that may change over time. It also
    defines a method for saving the state inside a memento and another method
    for restoring the state from it.
    """

    def __init__(self, state: str) -> None:
        """
        For the sake of simplicity, the originator's state is stored inside a single
        variable.
        """

        self._state = state
        print(f'Originator: My initial state is {self._state}.')

    def do_something(self) -> None:
        """
        The Originator's business logic may affect its internal state.
        Therefore, the client should backup the state before launching methods
        of the business logic via the save() method.
        """

        print('Originator: I\'m doing something important.')
        self._state = self._generate_random_string(30)
        print(f'Originator: And my state has changed to {self._state}.')

    @staticmethod
    def _generate_random_string(length: int = 10) -> str:
        return ''.join(sample(ascii_letters, length))

    def save(self) -> Originator.Memento:
        """
        Saves the current state inside a memento.
        """

        return Originator.Memento(self._state)

    def restore(self, memento: Originator.Memento) -> None:
        """
        Restores the Originator's state from a memento object.
        """

        self._state = memento._state
        print(f'Originator: My state has changed to {self._state}.')

    class Memento:
        """
        The Memento interface provides a way to retrieve the memento's metadata,
        such as creation date or name. However, it doesn't expose the Originator's
        state.
        """
        def __init__(self, state: str) -> None:
            """
            By using nested class, the Originator can access directly when
            restoring its state, while other object won't be able to do that.
            """
            self._state = state
            self._date = str(datetime.now())[:19]

        """
        The rest of the methods are used by the Caretaker to display metadata.
        """
        @property
        def name(self) -> str:
            return f'{self._date} / ({self._state[:9]}...)'

        @property
        def date(self) -> str:
            return self._date
