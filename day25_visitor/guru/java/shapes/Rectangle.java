package shapes;

import visitor.Visitor;

public class Rectangle extends BaseShape {
    private final int x;
    private final int y;
    private final int width;
    private final int height;

    public Rectangle(final int id, final int x, final int y, final int width, final int height) {
        super(id);
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
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

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }
}
