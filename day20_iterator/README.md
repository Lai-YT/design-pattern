The main idea of the **[Iterator pattern](https://refactoring.guru/design-patterns/iterator)** is to extract the traversal behavior of a collection into a separate object called an iterator.

In addition to implementing the algorithm itself, an iterator object encapsulates all of the traversal details, such as the current position and how many elements are left till the end. \
Because of this, several iterators can go through the same collection at the same time, independently of each other.
