// The Product interface declares the operations that all concrete products must
// implement.
export interface Product {
  operation(): string;
}

// Concrete Products provide various implementations of the Product interface.
export class ConcreteProduct1 implements Product {
  public operation(): string {
    return '{Result of the ConcreteProduct1}';
  }
}


export class ConcreteProduct2 implements Product {
  public operation(): string {
    return '{Result of the ConcreteProduct2}';
  }
}
