from typing import Union

from drink import *


class Client:
    def order(self,
              drink: Union[TeaType, CoffeeType],
              sugar: SugarType,
              ice: IceType) -> Drink:
        if isinstance(drink, TeaType):
            return Tea(drink, sugar, ice)
        if isinstance(drink, CoffeeType):
            return Coffee(drink, sugar, ice)

        raise TypeError('No such type of drink')
