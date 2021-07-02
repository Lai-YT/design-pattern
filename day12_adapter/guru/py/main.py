from adaptee import *
from adapter import *
from target import *


def client_code(target: Target) -> None:
    """
    The client code supports all classes that follow the Target interface.
    """

    print(target.request())


if __name__ == '__main__':
    print('Client: I can work just fine with the Target objects.')
    target = Target()
    client_code(target)
    print()

    print('Client: The Adaptee class has a weird interface. See, I don\'t understand it.')
    adaptee = Adaptee()
    print(f'Adaptee: {adaptee.specific_request()}')
    print()

    print('Client: But I can work with it via the Adapter.')
    composition_adapter = Composition.Adapter(adaptee)
    client_code(composition_adapter)
    inheritance_adapter = Inheritance.Adapter()
    client_code(inheritance_adapter)
    # Client: I can work just fine with the Target objects.
    # Target: The default target's behavior.
    #
    # Client: The Adaptee class has a weird interface. See, I don't understand it.
    # Adaptee: .eetpadA eht fo roivaheb laicepS
    #
    # Client: But I can work with it via the Adapter.
    # Composition Adapter: (TRANSLATED) Special behavior of the Adaptee.
    # Inheritance Adapter: (TRANSLATED) Special behavior of the Adaptee.
