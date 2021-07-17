from typing import List

from memento import Memento
from originator import Originator


class Caretaker:
    """
    The Caretaker doesn't depend on the Concrete Memento class. Therefore, it
    doesn't have access to the originator's state, stored inside the memento. It
    works with all mementos via the base Memento interface.
    """

    def __init__(self, originator: Originator) -> None:
        self._mementos: List[Memento] = []
        self._originator = originator

    def backup(self) -> None:
        print('Caretaker: Saving Originator\'s state...')
        self._mementos.append(self._originator.save())

    def undo(self) -> None:
        if not self._mementos:
            return
            
        memento: Memento = self._mementos.pop()
        print(f'Caretaker: Restoring state to {memento.name}.')
        try:
            self._originator.restore(memento)
        except Exception:
            self.undo()

    def show_history(self) -> None:
        print('Caretaker: Here\'s the list of mementos.')
        for memento in self._mementos:
            print(memento.name)
