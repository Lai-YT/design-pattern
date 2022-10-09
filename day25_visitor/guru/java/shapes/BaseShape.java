package shapes;

public abstract class BaseShape implements Shape {
    private final int id;

    public BaseShape(final int id) {
        this.id = id;
    }

    @Override
    public void move(final int x, final int y) {
        /* this method is left empty to to focus on those about Visitor */
    }

    @Override
    public void draw() {
        /* this method is left empty to to focus on those about Visitor */
    }

    public int getId() {
        return id;
    }
}
