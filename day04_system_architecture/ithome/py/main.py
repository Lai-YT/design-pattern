from client import Client
from drink import CoffeeType, Drink, IceType, SugarType, TeaType


if __name__ == '__main__':
    client = Client()

    tea: Drink = client.order(TeaType.OOLONG, SugarType.QUARTER, IceType.EASY)
    tea.describe()
    print()

    coffee: Drink = client.order(CoffeeType.AMERICANO, SugarType.FREE, IceType.HOT)
    coffee.describe()
    # It's a cup of oolong tea.
    # Sweetness level: quarter
    # Amount of ice: easy
    #
    # It's a cup of Americano.
    # Sweetness level: free
    # Amount of ice: hot
