# Production of cross-platform GUI elements

In this example, `Button`s play a *product* role and dialogs act as *creator*s.

Different types of `dialog`s require their own types of elements. \
That's why we create a subclass for each dialog type and override their factory methods.

Now, each dialog type will instantiate proper button classes. \
Base dialog works with products using their common interface, that's why its code remains functional after all changes.
