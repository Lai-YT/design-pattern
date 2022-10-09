package shapes;

import visitor.Visitor;

public class Circle extends Dot {
    private final int radius;

    public Circle(final int id, final int x, final int y, final int radius) {
        super(id, x, y);
        this.radius = radius;
    }

    @Override
    public String accept(final Visitor visitor) {
        return visitor.visit(this);
    }

    public int getRadius() {
        return radius;
    }
}
