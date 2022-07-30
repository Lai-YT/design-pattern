import { Creator, ConcreteCreator1, ConcreteCreator2 } from "./creator";

// The client code works with an instance of a concrete creator, albeit through
// its base interface. As long as the client keeps working with the creator via
// the base interface, you can pass it any creator's subclass.
function clientCode(creator: Creator): void {
  console.log('Client: I\'m not aware of the creator\'s class, but it still works.');
  console.log(creator.someOperation());
}

// The Application picks a creator's type depending on the configuration or
// environment.
console.log('App: Launched with the ConcreteCreator1.');
clientCode(new ConcreteCreator1());
console.log('');

console.log('App: Launched with the ConcreteCreator2.');
clientCode(new ConcreteCreator2());
// App: Launched with the ConcreteCreator1.
// Client: I'm not aware of the creator's class, but it still works.
// Creator: The same creator's code has just worked with {Result of the ConcreteProduct1}

// App: Launched with the ConcreteCreator2.
// Client: I'm not aware of the creator's class, but it still works.
// Creator: The same creator's code has just worked with {Result of the ConcreteProduct2}
