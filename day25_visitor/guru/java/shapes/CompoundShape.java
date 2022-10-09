package shapes;

import java.util.ArrayList;
import java.util.List;

import visitor.Visitor;

public class CompoundShape extends BaseShape {
    public final List<Shape> children = new ArrayList<>();

    public CompoundShape(final int id) {
        super(id);
    }

    @Override
    public String accept(final Visitor visitor) {
        return visitor.visit(this);
    }

    public void add(final Shape shape) {
        children.add(shape);
    }
}
