from abc import ABC, abstractmethod


class Order(ABC):
    @abstractmethod
    def show(self) -> None:
        pass
