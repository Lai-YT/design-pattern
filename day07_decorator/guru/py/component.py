from abc import ABC, abstractmethod
from overrides import overrides


class Component(ABC):
    """
    The base Component interface defines operations that can be altered by
    decorators.
    """

    @abstractmethod
    def operation(self) -> str:
        pass


class ConcreteComponent(Component):
    """
    Concrete Components provide default implementations of the operations. There
    might be several variations of these classes.
    """

    @overrides
    def operation(self) -> str:
        return 'ConcreteComponent'
