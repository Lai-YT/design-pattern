
// The Adaptee contains some useful behaviors, but its interface is
// incompatible with the existing client code.
// The Adaptee needs some adaptation before the client code can use it.
public class Adaptee {
  public string GetSpecificRequest() {
    return "Specific Request.";
  }
}
