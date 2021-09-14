from item import *
from order import *
from set import *


if __name__ == '__main__':
    print('Customization:')

    soup = Soup()
    salad = Salad()
    salad.decorate(soup)

    main_meal = MainMeal()
    main_meal.decorate(salad)

    drink = Drink()
    drink.decorate(main_meal)
    drink.show()

    print()
    print('Sets:')

    simple_set = SimpleSet()
    simple_set.show()
    # Customization:
    # --> soup
    # --> salad
    # --> main meal
    # --> drink
    #
    # Sets:
    # --> salad
    # --> main meal
    # --> drink
