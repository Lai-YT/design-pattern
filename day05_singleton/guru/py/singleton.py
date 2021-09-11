from __future__ import annotations
from threading import Lock


# This is a thread-safe implementation of Singleton.

# The Singleton class can be implemented in different ways in Python. Some
# possible methods include: base class, decorator, metaclass. We will use the
# metaclass because it is best suited for this purpose.
class SingletonMeta(type):

    _instances = {}
    
    _lock: Lock = Lock()
    # We now have a lock object that will be used to synchronize threads during
    # first access to the Singleton.

    def __call__(cls, *args, **kwargs) -> Singleton:
        # Possible changes to the value of the `__init__` argument do not affect
        # the returned instance.

        with cls._lock:
            if cls not in cls._instances:
                print('Generating new instance...')
                cls._instances[cls] = super().__call__(*args, *kwargs)
        return cls._instances[cls]


class Singleton(metaclass=SingletonMeta):
    def __init__(self, value: str) -> None:
        # We'll use this property to prove that our Singleton really works.
        self.value = value

    def some_business_logic(self) -> None:
        # Finally, any singleton should define some business logic, which can be
        # executed on its instance.

        print('Do some business logic')
