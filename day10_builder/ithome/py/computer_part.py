
class Processor:
    def __init__(self, name: str) -> None:
        self._name = name

    @property
    def name(self) -> str:
        return self._name


class Memory:
    def __init__(self, size: int) -> None:
        self._size = size

    @property
    def size(self) -> int:
        return self._size


class Graphics:
    def __init__(self, name: str) -> None:
        self._name = name

    @property
    def name(self) -> str:
        return self._name


class Storage:
    def __init__(self, size: int) -> None:
        self._size = size

    @property
    def size(self) -> int:
        return self._size
