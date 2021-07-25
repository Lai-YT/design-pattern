from typing import List

from originator import Originator


class Caretaker:
    def __init__(self, originator: Originator) -> None:
        self._originator = originator
        self._mementos: List[Originator.Memento] = []

    def backup(self) -> None:
        print('Caretaker: Saving Originator\'s state...')
        self._mementos.append(self._originator.save())

    def undo(self) -> None:
        if not self._mementos:
            return

        memento: Originator.Memento = self._mementos.pop()
        print(f'Caretaker: Restoring state to {memento.name}.')
        try:
            self._originator.restore(memento)
        except Exception as e:
            print(e)
            self.undo()

    def show_history(self) -> None:
        print('Caretaker: Here\'s the list of mementos.')
        for memento in self._mementos:
            print(memento.name)
