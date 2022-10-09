package shapes;

import java.util.ArrayList;
import java.util.List;

import visitor.Visitor;

public class CompoundShape implements Shape {
    public final List<Shape> children = new ArrayList<>();
    private final int id;

    public CompoundShape(final int id) {
        this.id = id;
    }

    @Override
    public String accept(final Visitor visitor) {
        return visitor.visit(this);
    }

    @Override
    public void move(final int x, final int y) {
        /* move shape */
    }

    @Override
    public void draw() {
        /* draw shape */
    }

    public int getId() {
        return id;
    }

    public void add(final Shape shape) {
        children.add(shape);
    }
}
