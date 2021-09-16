# Event subscription

In this example, the Observer pattern establishes indirect collaboration between \
objects of a text editor. Each time the `Editor` object changes, it notifies its \
subscribers. `EmailNotificationListener` and `LogOpenListener` react to these \
notifications by executing their primary behaviors.

Subscriber classes aren't coupled to the editor class and can be reused in other \
apps if needed. The `Editor` class depends only on the abstract subscriber interface. \
This allows adding new subscriber types without changing the editor's code.
