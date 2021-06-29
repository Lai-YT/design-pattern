from builder import *
from director import *
from product import *


def client_code(director: Director) -> None:
    """
    The client code creates a builder object, passes it to the director and then
    initiates the construction process. The end result is retrieved from the
    builder object.
    """

    builder = ConcreteBuilder1()
    director.builder = builder

    director.build_minimal_viable_product()
    builder.product.list_parts()
    print()

    director.build_full_featured_product()
    builder.product.list_parts()
    print()

    # Remember, the Builder pattern can be used without a Director class.
    print('Building customized product...')
    builder.produce_part_a()
    builder.produce_part_b()
    print('Done.')
    builder.product.list_parts()


if __name__ == '__main__':
    director = Director()
    client_code(director)
    # ConcreteBuilder1: Ready for a new build.
    # Director: Building basic product...
    # Done.
    # ConcreteBuilder1: Ready for a new build.
    # Product parts: PartA1
    #
    # Director: Building full featured product...
    # Done.
    # ConcreteBuilder1: Ready for a new build.
    # Product parts: PartA1, PartB1, PartC1
    #
    # Building customized product...
    # Done.
    # ConcreteBuilder1: Ready for a new build.
    # Product parts: PartA1, PartB1
