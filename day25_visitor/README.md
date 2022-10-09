The **[Visitor pattern](https://refactoring.guru/design-patterns/visitor)** suggests that you place the new behavior into a separate class called *visitor*, instead of trying to integrate it into existing classes. \
The original object that had to perform the behavior is now passed to one of the visitor's methods as an argument, providing the method access to all necessary data contained within the object.

Even though the Visitor pattern is built on the *[double dispatch](https://refactoring.guru/design-patterns/visitor-double-dispatch)* principle, that's not its primary purpose. \
Visitor lets you add "external" operations to a whole class hierarchy without changing the existing code of these classes.
