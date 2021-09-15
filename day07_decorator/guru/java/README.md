# Encoding and compression decorators

This example shows how you can adjust the behavior of an object without changing \
its code.

Initially, the business logic class could only read and write data in plain text. \
Then we created several small wrapper classes that add new behavior after executing \
standard operations in a wrapped object.

The first wrapper encrypts and decrypts data, and the second one compresses and \
extracts data.

You can even combine these wrappers by wrapping one decorator with another.
