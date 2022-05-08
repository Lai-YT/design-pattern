# Step-by-step car production

In this example, the *Builder pattern* allows step by step construction of different car models.

The example also shows how `Builder` produces products of different kinds (car manual) using the same building steps.

The `Director` controls the order of the construction. It knows which building steps to call to produce this or that car model. It works with builders only via their common interface. This allows passing different types of builders to the director.

The end result is retrieved from the builder object because the director can’t know the type of resulting product. Only the `Builder` object knows what does it build exactly.
