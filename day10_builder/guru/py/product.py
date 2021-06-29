from typing import Any, List


class Product1:
    """
    It makes sense to use the Builder pattern only when your products are quite
    complex and require extensive configuration.

    Unlike in other creational patterns, different concrete builders can produce
    unrelated products. In other words, results of various builders may not
    always follow the same interface.
    """

    def __init__(self) -> None:
        self._parts: List[Any] = list()

    def add(self, part: Any) -> None:
        self._parts.append(part)

    def list_parts(self) -> None:
        print(f"Product parts: {', '.join(self._parts)}")
