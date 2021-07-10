from subsystem import *


class Facade:
    """
    The Facade class provides a simple interface to the complex logic of one or
    several subsystems. The Facade delegates the client requests to the
    appropriate objects within the subsystem. The Facade is also responsible for
    managing their lifecycle. All of this shields the client from the undesired
    complexity of the subsystem.
    """

    def __init__(self, subsystem_1: Subsystem1 = None, subsystem_2: Subsystem2 = None) -> None:
        """
        Depending on your application's needs, you can provide the Facade with
        existing subsystem objects or force the Facade to create them on its
        own.
        """

        self._subsystem_1 = subsystem_1 if subsystem_1 is not None else Subsystem1()
        self._subsystem_2 = subsystem_2 if subsystem_2 is not None else Subsystem2()

    def operation(self) -> str:
        """
        The Facade's methods are convenient shortcuts to the sophisticated
        functionality of the subsystems. However, clients get only to a fraction
        of a subsystem's capabilities.
        """

        result: str = 'Facade initializes subsystems.\n'
        result += self._subsystem_1.operation_1()
        result += self._subsystem_2.operation_1()
        result += 'Facade orders subsystems to perform the action.\n'
        result += self._subsystem_1.operation_n()
        result += self._subsystem_2.operation_z()
        return result
