from discount import *
from drink import *
from order import *


if __name__ == '__main__':
    print('Start a 10% off order.')
    drink_order = DrinkOrder(MultiplyDiscount(0.9))
    drink_order.order(Coffee(90))
    drink_order.order(MilkTea(55))
    print(f'Original price: {90 + 55} dollars.')

    print(f'After 10% off: {drink_order.get_total_price()} dollars.')

    print('Change to a minus 10 dollars discount order.')
    drink_order.change_discount(MinusDiscount(10))
    print(f'After 10 dollars off: {drink_order.get_total_price()} dollars.')
    # Start a 10% off order.
    # Order: A 90-dollar drink.
    # Order: A 55-dollar drink.
    # Original price: 145 dollars.
    # After 10% off: 130 dollars.
    # Change to a minus 10 dollars discount order.
    # After 10 dollars off: 125 dollars.
