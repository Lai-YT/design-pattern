from observer import *
from subject import *


def client_code() -> None:
    subject = ConcreteSubject()

    observer_a = ConcreteObserverA()
    subject.attach(observer_a)

    observer_b = ConcreteObserverB()
    subject.attach(observer_b)

    print()
    subject.some_business_logic()
    print()
    subject.some_business_logic()

    subject.detach(observer_a)

    print()
    subject.some_business_logic()


if __name__ == '__main__':
    # State of the Subject is generated randomly,
    # so the output of client code varies every time.
    client_code()
    # Subject: Attached an observer.
    # Subject: Attached an observer.
    #
    # Subject: I'm doing something important.
    # Subject: My state has just changed to 2.
    # Subject: Notifying observers...
    # ConcreteObserverA: Reacted to the event.
    # ConcreteObserverB: Reacted to the event.
    #
    # Subject: I'm doing something important.
    # Subject: My state has just changed to 5.
    # Subject: Notifying observers...
    # ConcreteObserverB: Reacted to the event.
    #
    # Subject: I'm doing something important.
    # Subject: My state has just changed to 6.
    # Subject: Notifying observers...
    # ConcreteObserverB: Reacted to the event.
