from context import *
from strategy import *


# The client code picks a concrete strategy and passes it to the context.
# The client should be aware of the differences between strategies in order
# to make the right choice.
def client_code() -> None:
    context = Context(ConcreteStrategyA())
    print("Client: Strategy is set to normal sorting.")
    context.do_some_business_logic()
    print()

    context.strategy = ConcreteStrategyB()
    print("Client: Strategy is set to reverse sorting.")
    context.do_some_business_logic()


if __name__ == "__main__":
    client_code()
    # Client: Strategy is set to normal sorting.
    # Context: Sorting data using the strategy... (not sure how it'll do it)
    # Result: a,b,c,d,e
    #
    # Client: Strategy is set to reverse sorting.
    # Context: Sorting data using the strategy... (not sure how it'll do it)
    # Result: e,d,c,b,a
