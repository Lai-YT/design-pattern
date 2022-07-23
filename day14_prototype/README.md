The **[Prototype pattern](https://refactoring.guru/design-patterns/prototype)** delegates the cloning process to the actual objects that are being cloned. \
The pattern declares a common interface for all objects that support cloning. \
This interface lets you clone an object without coupling your code to the class of that object. Usually, such an interface contains just a single `clone` method.

An object that supports cloning is called a *prototype*. \
When your objects have dozens of fields and hundreds of possible configurations, cloning them might serve as an alternative to subclassing.
