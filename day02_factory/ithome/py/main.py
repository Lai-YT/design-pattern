from factory import *
from product import *


def client_code() -> None:
    fries_fac: Factory = FrenchFriesFactory()
    salty_fries: Product = fries_fac.get_product()
    non_salty_fries: Product = fries_fac.get_product('non-salty')

    salty_fries.describe()
    non_salty_fries.describe()


if __name__ == '__main__':
    client_code()
    # I'm salty french fries
    # I'm non-salty french fries
