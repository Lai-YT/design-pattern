package shapes;

import visitor.Visitor;

public class Dot extends BaseShape {
    private final int x;
    private final int y;

    public Dot(final int id, final int x, final int y) {
        super(id);
        this.x = x;
        this.y = y;
    }

    @Override
    public String accept(final Visitor visitor) {
        return visitor.visit(this);
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}
