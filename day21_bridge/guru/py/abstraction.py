from implementation import Implementation


class Abstraction:
    """
    The Abstraction defines the interface for the "control" part of the two
    class hierarchies. It maintains a reference to an object of the
    Implementation hierarchy and delegates all of the real work to this object.
    """

    def __init__(self, implementation: Implementation) -> None:
        self._implementation = implementation

    def operation(self) -> str:
        return ('Abstraction: Base operation with\n'
                + self._implementation.operation_implementation())


class ExtendedAbstraction(Abstraction):
    """
    You can extend the Abstraction without changing the Implementation classes.
    """

    def operation(self) -> str:
        return ('ExtendedAbstraction: Extended operation with\n'
                + self._implementation.operation_implementation())
