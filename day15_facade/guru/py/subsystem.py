
class Subsystem1:
    """
    The Subsystem can accept requests either from the facade or client directly.
    In any case, to the Subsystem, the Facade is yet another client, and it's
    not a part of the Subsystem.
    """

    def operation_1(self) -> str:
        return 'Subsystem1: Ready!\n'

    # ...

    def operation_n(self) -> str:
        return 'Subsystem1: Go!\n'


class Subsystem2:
    """
    Some facades can work with multiple subsystems at the same time.
    """

    def operation_1(self) -> str:
        return 'Subsystem2: Get ready!\n'

    # ...

    def operation_z(self) -> str:
        return 'Subsystem2: Fire!\n'
