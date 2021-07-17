from caretaker import Caretaker
from originator import Originator


def client_code() -> None:
    originator = Originator('Super-duper-super-puper-super')
    caretaker = Caretaker(originator)
    print()

    caretaker.backup()
    originator.do_something()
    print()

    caretaker.backup()
    originator.do_something()
    print()

    caretaker.backup()
    originator.do_something()
    print()

    caretaker.show_history()
    print()

    print('Client: Now, let\'s rollback!')
    caretaker.undo()
    print()

    print('Client: Once more!')
    caretaker.undo()


if __name__ == '__main__':
    client_code()
    # Originator: My initial state is Super-duper-super-puper-super.
    #
    # Caretaker: Saving Originator's state...
    # Originator: I'm doing something important.
    # Originator: And my state has changed to kZfMRHroLcgdniFWNDSeBlshIOJQGj.
    #
    # Caretaker: Saving Originator's state...
    # Originator: I'm doing something important.
    # Originator: And my state has changed to jfnyrhPwTdYJZOtVmuicIGBxFUbWpv.
    #
    # Caretaker: Saving Originator's state...
    # Originator: I'm doing something important.
    # Originator: And my state has changed to ZORwcyvSXpYAsWQgdHeIhtmqokDBxV.
    #
    # Caretaker: Here's the list of mementos.
    # 2021-07-17 23:31:14 / (Super-dup...)
    # 2021-07-17 23:31:14 / (kZfMRHroL...)
    # 2021-07-17 23:31:14 / (jfnyrhPwT...)
    #
    # Client: Now, let's rollback!
    # Caretaker: Restoring state to 2021-07-17 23:31:14 / (jfnyrhPwT...).
    # Originator: My state has changed to None.
    #
    # Client: Once more!
    # Caretaker: Restoring state to 2021-07-17 23:31:14 / (kZfMRHroL...).
    # Originator: My state has changed to None.
