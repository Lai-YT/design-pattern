from typing import Optional

from handler import Handler, DogHandler, MonkeyHandler, SquirrelHandler


def client_code(handler: Handler) -> None:
    """
    The client code is usually suited to work with a single handler. In most
    cases, it is not even aware that the handler is part of a chain.
    """

    for food in ['Nut', 'Banana', 'Cup of coffee']:
        print(f'Client: Who wants a {food}?')
        result: Optional[str] = handler.handle(food)
        if result is not None:
            print(f'    {result}')
        else:
            print(f'    {food} was left untouched.')


if __name__ == '__main__':
    monkey = MonkeyHandler()
    squirrel = SquirrelHandler()
    dog = DogHandler()

    monkey.set_next(squirrel).set_next(dog)

    # The client should be able to send a request to any handler, not just the
    # first one in the chain.
    print('Chain: Monkey -> Squirrel -> Dog')
    client_code(monkey)
    print()

    print('Subchain: Squirrel -> Dog')
    client_code(squirrel)
    # Chain: Monkey -> Squirrel -> Dog
    # Client: Who wants a Nut?
    #     Squirrel: I'll eat the Nut.
    # Client: Who wants a Banana?
    #     Monkey: I'll eat the Banana.
    # Client: Who wants a Cup of coffee?
    #     Cup of coffee was left untouched.
    #
    # Subchain: Squirrel -> Dog
    # Client: Who wants a Nut?
    #     Squirrel: I'll eat the Nut.
    # Client: Who wants a Banana?
    #     Banana was left untouched.
    # Client: Who wants a Cup of coffee?
    #     Cup of coffee was left untouched.
