**[Composite](https://refactoring.guru/design-patterns/composite)** is a structural design pattern that lets you compose objects into tree structures and then work with these structures as if they were individual objects.

Also known as: Object Tree

The greatest benefit of this approach is that you don't need to care about the concrete classes of objects that compose the tree.  \
You don't need to know whether an object is a simple `product` or a sophisticated `box`.  \
You can treat them all the same via the common interface.  \
When you call a method, the objects themselves pass the request down the tree.
