from typing import List

from command import Command


class Invoker:
    def __init__(self) -> None:
        self._command_list: List[Command] = []

    def set_command(self, command: Command) -> None:
        self._command_list.append(command)
        print('Waiting for execution...')

    def execute(self) -> None:
        print('Do: ', end='')
        if self._command_list:
            self._command_list[-1].execute()
        else:
            print()

    def undo(self) -> None:
        if self._command_list:
            self._command_list.pop()
        print('Execute the previous command...')
        self.execute()
