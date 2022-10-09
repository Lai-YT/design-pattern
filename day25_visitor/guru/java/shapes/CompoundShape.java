package shapes;

import java.util.ArrayList;
import java.util.List;

public class CompoundShape implements Shape {
    private final int id;
    private final List<Shape> children = new ArrayList<>();

    public CompoundShape(final int id) {
        this.id = id;
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
