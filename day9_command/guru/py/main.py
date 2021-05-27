from command import *
from invoker import *
from receiver import *


def client_code() -> None:
    """
    The client code can parameterize an invoker with any commands.
    """

    invoker = Invoker()
    invoker.set_on_start(SimpleCommand('Say Hi!'))
    receiver = Receiver()
    invoker.set_on_finish(ComplexCommand(receiver, 'Send email', 'Save report'))

    invoker.do_something_important()


if __name__ == '__main__':
    client_code()
    # Invoker: Does anybody want something done before I begin?
    # SimpleCommand: See, I can do simple things like printing (Say Hi!)
    # Invoker: ...doing something really important...
    # Invoker: Does anybody want something done after I finish?
    # ComplexCommand: Complex stuff should be done by a receiver object.
    # Receiver: Working on (Send email.)
    # Receiver: Also working on (Save report.)
