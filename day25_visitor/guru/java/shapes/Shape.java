package shapes;

import visitor.Visitor;

public interface Shape {
    /** Concrete shapes override this method to "double dispatch" the concrete type. */
    String accept(Visitor visitor);
    void move(int x, int y);
    void draw();
}
