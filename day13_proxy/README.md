The **[Proxy pattern](https://refactoring.guru/design-patterns/proxy)** suggests that you create a new proxy class with the same interface as an original service object. \
Then you update your app so that it passes the proxy object to all of the original object's clients. \
Upon receiving a request from a client, the proxy creates a real service object, does some work (access control, caching, etc.) and then and delegates all the work to it.
