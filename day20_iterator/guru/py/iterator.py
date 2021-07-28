"""
To create an iterator in Python, there are two abstract classes from the built-
in `collections` module - Iterable, Iterator. We need to implement the
`__iter__()` method in the iterated object (collection), and the `__next__ ()`
method in the iterator.
"""

from __future__ import annotations
from collections.abc import Iterator
from typing import Any, List


class AlphabeticalOrderIterator(Iterator):
    """
    Concrete Iterators implement various traversal algorithms. These classes
    store the current traversal position at all times.
    """

    def __init__(self, collection: List[Any], reverse: bool = False) -> None:
        self._collection = collection
        # This attribute indicates the traversal direction.
        self._reverse = reverse
        """
        `_position` attribute stores the current traversal position. An iterator may
        have a lot of other fields for storing iteration state, especially when it
        is supposed to work with a particular kind of collection.
        """
        self._position = -1 if reverse else 0

    def __next__(self) -> Any:
        """
        The __next__() method must return the next item in the sequence. On
        reaching the end, and in subsequent calls, it must raise StopIteration.
        """
        try:
            value = self._collection[self._position]
            self._position += -1 if self._reverse else 1
        except IndexError:
            raise StopIteration

        return value
