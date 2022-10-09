package shapes;

import visitor.Visitor;

public class Dot implements Shape {
    private final int id;
    private final int x;
    private final int y;

    public Dot(final int id, final int x, final int y) {
        this.id = id;
        this.x = x;
        this.y = y;
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

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getId() {
        return id;
    }
}
