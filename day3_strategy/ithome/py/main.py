from calculator import *
from strategy import *


def client_code() -> None:
    calculator = Calculator()

    calculator.set_strategy(DoType.ADD)
    print('5 + 9 = ', calculator.execute(5, 9))

    calculator.set_strategy(DoType.MINUS)
    print('5 - 9 = ', calculator.execute(5, 9))

    calculator.set_strategy(DoType.MULTIPLY)
    print('5 * 9 = ', calculator.execute(5, 9))

    calculator.set_strategy(DoType.DIVIDE)
    print('5 // 9 = ', calculator.execute(5, 9))


if __name__ == '__main__':
    client_code()
    # 5 + 9 =  14
    # 5 - 9 =  -4
    # 5 * 9 =  45
    # 5 // 9 =  0
