from builder import *


class Director:
    """
    The Director is only responsible for executing the building steps in a
    particular sequence. It is helpful when producing products according to a
    specific order or configuration. Strictly speaking, the Director class is
    optional, since the client can control builders directly.
    """

    @property
    def builder(self) -> Builder:
        return self._builder

    @builder.setter
    def builder(self, builder: Builder) -> None:
        """
        The Director works with any builder instance that the client code passes
        to it. This way, the client code may alter the final type of the newly
        assembled product.
        """

        self._builder = builder

    """
    The Director can construct several product variations using the same
    building steps.
    """
    def build_minimal_viable_product(self) -> None:
        print('Director: Building basic product...')
        self._builder.produce_part_a()
        print('Done.')

    def build_full_featured_product(self) -> None:
        print('Director: Building full featured product...')
        self._builder.produce_part_a()
        self._builder.produce_part_b()
        self._builder.produce_part_c()
        print('Done.')
