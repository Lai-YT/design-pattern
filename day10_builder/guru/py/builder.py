from abc import ABC, abstractmethod, abstractproperty
from overrides import overrides


from product import *


class Builder(ABC):
    """
    The Builder interface specifies methods for creating the different parts of
    the Product objects.
    """

    @abstractproperty
    def product(self) -> None:
        pass

    @abstractmethod
    def produce_part_a(self) -> None:
        pass

    @abstractmethod
    def produce_part_b(self) -> None:
        pass

    @abstractmethod
    def produce_part_c(self) -> None:
        pass


class ConcreteBuilder1(Builder):
    """
    The Concrete Builder classes follow the Builder interface and provide
    specific implementations of the building steps. Your program may have
    several variations of Builders, implemented differently.
    """

    def __init__(self) -> None:
        """
        A fresh builder instance should contain a blank product object, which is
        used in further assembly.
        """

        self.reset()

    def reset(self) -> None:
        self._product = Product1()
        print('ConcreteBuilder1: Ready for a new build.')

    @property
    @overrides
    def product(self) -> Product1:
        """
        Concrete Builders are supposed to provide their own methods for
        retrieving results. That's because various types of builders may create
        entirely different products that don't follow the same interface.
        Therefore, such methods cannot be declared in the base Builder interface
        (at least in a statically typed programming language).

        Usually, after returning the end result to the client, a builder
        instance is expected to be ready to start producing another product.
        That's why it's a usual practice to call the reset method at the end of
        the `getProduct` method body. However, this behavior is not mandatory,
        and you can make your builders wait for an explicit reset call from the
        client code before disposing of the previous result.
        """

        product: Product1 = self._product
        self.reset()
        return product

    @overrides
    def produce_part_a(self) -> None:
        self._product.add('PartA1')

    @overrides
    def produce_part_b(self) -> None:
        self._product.add('PartB1')

    @overrides
    def produce_part_c(self) -> None:
        self._product.add('PartC1')
