from command import *


class Invoker:
    """
    The Invoker is associated with one or several commands. It sends a request
    to the command.
    """

    def __init__(self) -> None:
        """
        Initialize commands.
        """

        self._on_start: Command = None
        self._on_finish: Command = None

    def set_on_start(self, command: Command) -> None:
        self._on_start = command

    def set_on_finish(self, command: Command) -> None:
        self._on_finish = command

    def do_something_important(self) -> None:
        """
        The Invoker does not depend on concrete command or receiver classes. The
        Invoker passes a request to a receiver indirectly, by executing a
        command.
        """

        print('Invoker: Does anybody want something done before I begin?')
        if self._on_start:
            self._on_start.execute()

        print('Invoker: ...doing something really important...')

        print('Invoker: Does anybody want something done after I finish?')
        if self._on_finish:
            self._on_finish.execute()
