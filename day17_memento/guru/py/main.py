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
    # Originator: And my state has changed to GdfTMwWcBVnPIjRAtKEgsrYiUvmkFp.
    #
    # Caretaker: Saving Originator's state...
    # Originator: I'm doing something important.
    #
    # Originator: And my state has changed to fevOhEGTjpztcknyMSDqgJiNbaAYHC.
    #
    # Caretaker: Saving Originator's state...
    # Originator: I'm doing something important.
    # Originator: And my state has changed to ibZLBroXuzNEGAcQjKJtWdqDIySlnY.
    #
    # Caretaker: Here's the list of mementos.
    # 2021-07-25 14:24:18 / (Super-dup...)
    # 2021-07-25 14:24:18 / (GdfTMwWcB...)
    # 2021-07-25 14:24:18 / (fevOhEGTj...)
    #
    # Client: Now, let's rollback!
    # Caretaker: Restoring state to 2021-07-25 14:24:18 / (fevOhEGTj...).
    # Originator: My state has changed to fevOhEGTjpztcknyMSDqgJiNbaAYHC.
    #
    # Client: Once more!
    # Caretaker: Restoring state to 2021-07-25 14:24:18 / (GdfTMwWcB...).
    # Originator: My state has changed to GdfTMwWcBVnPIjRAtKEgsrYiUvmkFp.
