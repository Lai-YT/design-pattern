#include <list>
#include <string>

// The base Component class declares common operations for both simple and
// complex objects of a composition.
class Component {
public:
  // Optionally, the base Component can declare an interface for setting and
  // accessing a parent of the component in a tree structure. It can also
  // provide some default implementation for these methods.
  void SetParent(Component* const parent) {
    parent_ = parent;
  }

  const Component* GetParent() const {
    return parent_;
  }

  // In some cases, it would be beneficial to define the child-management
  // operations right in the base Component class. This way, you won't need to
  // expose any concrete component classes to the client code, even during the
  // object tree assembly. The downside is that these methods will be empty for
  // the leaf-level components.
  virtual void Add(Component* const component) {/* empty */}
  virtual void Remove(Component* const component) {/* empty */}

  // You can provide a method that lets the client code figure out whether a
  // component can bear children.
  virtual bool IsComposite() const = 0;

  // The base Component may implement some default behavior or leave it to
  // concrete classes (by declaring the method containing the behavior as
  // "abstract").
  virtual std::string Operation() const = 0;

  virtual ~Component() = default;

private:
  Component* parent_ = nullptr;
};

// The Leaf class represents the end objects of a composition. A leaf can't have
// any children.
// Usually, it's the Leaf objects that do the actual work, whereas Composite
// objects only delegate to their sub-components.
class Leaf : public Component {
public:
  bool IsComposite() const override {
    return false;
  }

  std::string Operation() const override {
    return "Leaf";
  }
};

// The Composite class represents the complex components that may have children.
// Usually, the Composite objects delegate the actual work to their children and
// then "sum-up" the result.
class Composite : public Component {
public:
  // A composite object can add or remove other components (both simple or
  // complex) to or from its child list.
  void Add(Component* const component) override {
    children_.push_back(component);
    component->SetParent(this);
  }

  // Have in mind that this method removes the pointer to the list but doesn't
  // frees the memory, you should do it manually or better use smart pointers.
  void Remove(Component* const component) override {
    children_.remove(component);
    component->SetParent(nullptr);
  }

  bool IsComposite() const override {
    return true;
  }

  // The Composite executes its primary logic in a particular way. It traverses
  // recursively through all its children, collecting and summing their results.
  // Since the composite's children pass these calls to their children and so
  // forth, the whole object tree is traversed as a result.
  std::string Operation() const override {
    std::string result = "";
    for (const auto* const component : children_) {
      result += component->Operation();
      if (component != children_.back()) {
        result += '+';
      }
    }
    return "Branch(" + result + ")";
  }

private:
  std::list<Component*> children_;
};
