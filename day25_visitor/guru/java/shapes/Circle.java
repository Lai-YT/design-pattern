package shapes;

public class Circle extends Dot {
    private final int radius;

    public Circle(final int id, final int x, final int y, final int radius) {
        super(id, x, y);
        this.radius = radius;
    }

    public int getRadius() {
        return radius;
    }
}
