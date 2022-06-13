The **[Template Method](https://refactoring.guru/design-patterns/template-method)** pattern suggests that you break down an algorithm into a series of steps, turn these steps into methods, and put a series of calls to these methods inside a single template method. \
The steps may either be *abstract*, or have some default implementation. \
To use the algorithm, the client is supposed to provide its own subclass, implement all abstract steps, and override some of the optional ones if needed (but not the template method itself).
