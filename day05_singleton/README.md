The **[Singleton pattern](https://refactoring.guru/design-patterns/singleton)** solves two problems at the same time, violating the Single \
Responsibility Principle:

1. Ensure that a class has just a single instance. \
Why would anyone want to control how many instances a class has? The most common \
reason for this is to control access to some shared resource—for example, a \
database or a file.

1. Provide a global access point to that instance. \
Remember those global variables that you (all right, me) used to store some \
essential objects? While they’re very handy, they’re also very unsafe since any \
code can potentially overwrite the contents of those variables and crash the app.

Nowadays, the Singleton pattern has become so popular that people may call \
something a singleton even if it solves just one of the listed problems.
