from abc import ABC, abstractmethod


class AbstractClass(ABC):
    """
    The Abstract Class defines a template method that contains a skeleton of
    some algorithm, composed of calls to (usually) abstract primitive
    operations.

    Concrete subclasses should implement these operations, but leave the
    template method itself intact.
    """

    def template_method(self) -> None:
        """
        The template method defines the skeleton of an algorithm.
        """

        self.base_operation_1()
        self.required_operation_1()
        self.base_operation_2()
        self.hook_1()
        self.required_operation_2()
        self.base_operation_3()
        self.hook_2()

    # These operations already have implementations.
    def base_operation_1(self) -> None:
        print('AbstractClass says: I am doing the bulk of the work.')

    def base_operation_2(self) -> None:
        print('AbstractClass says: But I let subclasses override some operations.')

    def base_operation_3(self) -> None:
        print('AbstractClass says: But I am doing the bulk of the work anyway.')

    # These operations have to be implemented in subclasses.
    @abstractmethod
    def required_operation_1(self) -> None:
        pass

    @abstractmethod
    def required_operation_2(self) -> None:
        pass

    # These are "hooks." Subclasses may override them, but it's not mandatory
    # since the hooks already have default (but empty) implementation. Hooks
    # provide additional extension points in some crucial places of the
    # algorithm.
    def hook_1(self) -> None:
        pass

    def hook_2(self) -> None:
        pass
