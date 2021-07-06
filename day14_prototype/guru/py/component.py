from __future__ import annotations
import copy
from typing import Dict, List


class SelfReferencingEntity:
    def __init__(self) -> None:
        self.parent: object = None

    @property
    def parent(self) -> object:
        return self._parent

    @parent.setter
    def parent(self, parent: object) -> None:
        self._parent = parent


class SomeComponent:
    """
    Python provides its own interface of Prototype via `copy.copy` and
    `copy.deepcopy` functions. And any class that wants to implement custom
    implementations have to override `__copy__` and `__deepcopy__` member
    functions.
    """

    def __init__(self,
                 some_int: int,
                 some_list_of_objects: List[object],
                 some_circular_ref: object) -> None:
        self.some_int = some_int
        self.some_list_of_objects = some_list_of_objects
        self.some_circular_ref = some_circular_ref

    def __copy__(self) -> SomeComponent:
        """
        Create a shallow copy. This method will be called whenever someone calls
        `copy.copy` with this object and the returned value is returned as the
        new shallow copy.
        """

        # First, let's create copies of the nested objectes.
        some_list_of_objects: List[object] = copy.copy(self.some_list_of_objects)
        some_circular_ref: object = copy.copy(self.some_circular_ref)

        # Then, let's clone the object itself, using the prepared clones of the
        # nessted objects.
        new_component: SomeComponent = self.__class__(
            self.some_int, some_list_of_objects, some_circular_ref
        )
        new_component.__dict__.update(self.__dict__)

        return new_component

    def __deepcopy__(self, memo: Dict[int, object] = None) -> SomeComponent:
        """
        Create a deep copy. This method will be called whenever someone calls
        `copy.deepcopy` with this object and the returned value is returned as
        the new deep copy.

        What is the use of the argument `memo`? Memo is the dictionary that is
        used by the `deepcopy` library to prevent infinite recursive copies in
        instances of circular references. Pass it to all the `deepcopy` calls
        you make in the `__deepcopy__` implementation to prevent infinite
        recursions.
        """

        if not memo:
            memo = dict()

        # First, let's create copies of the nested objects.
        some_list_of_objects: List[object] = copy.deepcopy(self.some_list_of_objects, memo)
        some_circular_ref: object = copy.deepcopy(self.some_circular_ref, memo)

        # Then, let's clone the object itself, using the prepared clones of the
        # nested objects.
        new_component: SomeComponent = self.__class__(
            self.some_int, some_list_of_objects, some_circular_ref
        )
        new_component.__dict__ = copy.deepcopy(self.__dict__, memo)

        return new_component
