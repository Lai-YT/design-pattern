from adaptee import *
from target import *


# outer class use as a namespace
class Composition:
    # this is so-called the Object Adapter Pattern
    class Adapter(Target):
        """
        The Adapter makes the Adaptee's interface compatible with the Target's
        interface via composition.
        """

        def __init__(self, adaptee: Adaptee) -> None:
            self._adaptee = adaptee

        def request(self) -> str:
            # reverse
            return f'Composition Adapter: (TRANSLATED) {self._adaptee.specific_request()[::-1]}'


# outer class use as a namespace
class Inheritance:
    # this is so-called the Class Adapter Pattern
    class Adapter(Target, Adaptee):
        """
        The Adapter makes the Adaptee's interface compatible with the Target's
        interface via multiple inheritance.
        """

        def request(self) -> str:
            return f'Inheritance Adapter: (TRANSLATED) {self.specific_request()[::-1]}'
