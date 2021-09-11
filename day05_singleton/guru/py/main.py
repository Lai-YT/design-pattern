from threading import Thread

from singleton import Singleton


def test_singleton(value: str) -> None:
    singleton = Singleton(value)
    print(singleton.value)


def client_code() -> None:
    print('If you see the same value, then singleton was reused;\n'
          'if you see different values, then 2 singletons were created.\n\n'
          'Result:')

    process1 = Thread(target=test_singleton, args=("FOO",))
    process2 = Thread(target=test_singleton, args=("BAR",))

    process1.start()
    process2.start()


if __name__ == '__main__':
    client_code()
    # If you see the same value, then singleton was reused;
    # if you see different values, then 2 singletons were created.
    #
    # Result:
    # Generating new instance...
    # FOO
    # FOO
