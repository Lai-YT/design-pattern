from __future__ import annotations
from collections.abc import Iterable
from typing import Any, List, Optional

from iterator import AlphabeticalOrderIterator


class WordsCollection(Iterable):
    """
    Concrete Collections provide one or several methods for retrieving fresh
    iterator instances, compatible with the collection class.
    """

    def __init__(self, collection: Optional[List[Any]] = None) -> None:
        if collection is None:
            collection = []
        self._collection = collection

    def __iter__(self) -> AlphabeticalOrderIterator:
        """
        The __iter__() method returns the iterator object itself, by default we
        return the iterator in ascending order.
        """
        
        return AlphabeticalOrderIterator(self._collection)

    def get_reverse_iterator(self) -> AlphabeticalOrderIterator:
        return AlphabeticalOrderIterator(self._collection, reverse=True)

    def add_item(self, item: Any) -> None:
        self._collection.append(item)
