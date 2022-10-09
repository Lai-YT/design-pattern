package shapes;

public class Dot implements Shape {
    private int id;
    private final int x;
    private final int y;

    public Dot(final int id, final int x, final int y) {
        this.x = x;
        this.y = y;
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
