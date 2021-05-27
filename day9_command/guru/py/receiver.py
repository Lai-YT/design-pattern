
class Receiver:
    """
    The Receiver classes contain some important business logic. They know how to
    perform all kinds of operations, associated with carrying out a request. In
    fact, any class may serve as a Receiver.
    """

    def do_something(self, a: str) -> None:
        print(f'Receiver: Working on ({a}.)')

    def do_something_else(self, b: str) -> None:
        print(f'Receiver: Also working on ({b}.)')
