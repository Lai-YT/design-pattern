class ConcreteComponentA;
class ConcreteComponentB;


// The Visitor Interface declares a set of visiting methods that correspond to
// component classes. The signature of a visiting method allows the visitor to
// identify the exact class of the component that it's dealing with.
class Visitor {
public:
  virtual void VisitConcreteComponentA(const ConcreteComponentA& element) const = 0;
  virtual void VisitConcreteComponentB(const ConcreteComponentB& element) const = 0;

  virtual ~Visitor() = default;
};


// Concrete Visitors implement several versions of the same algorithm, which can
// work with all concrete component classes.
//
// You can experience the biggest benefit of the Visitor pattern when using it
// with a complex object structure, such as a Composite tree. In this case, it
// might be helpful to store some intermediate state of the algorithm while
// executing visitor's methods over various objects of the structure.

class ConcreteVisitor1 : public Visitor {
public:
  void VisitConcreteComponentA(const ConcreteComponentA& element) const override;
  void VisitConcreteComponentB(const ConcreteComponentB& element) const override;
};


class ConcreteVisitor2 : public Visitor {
public:
  void VisitConcreteComponentA(const ConcreteComponentA& element) const override;
  void VisitConcreteComponentB(const ConcreteComponentB& element) const override;
};
