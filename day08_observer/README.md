The object that has some interesting state is often called *subject*, but since it’s \
 lso going to notify other objects about the changes to its state, we’ll call it \
*publisher*. All other objects that want to track changes to the publisher’s state \
are called *subscribers*.

The **[Observer pattern](https://refactoring.guru/design-patterns/observer)** suggests that you add a subscription mechanism to the \
publisher class so individual objects can subscribe to or unsubscribe from a \
stream of events coming from that publisher. Fear not! Everything isn’t as \
complicated as it sounds. In reality, this mechanism consists of 1) an array \
field for storing a list of references to subscriber objects and 2) several \
public methods which allow adding subscribers to and removing them from that list.
