package shapes;

/// Common shaoe interface
public abstract class Shape {
    public int x;
    public int y;
    public String color;

    public Shape() {}

    /* A prototype class must define the alternative constructor that accepts an object
        of that class as an argument. */
    public Shape(final Shape that) {
        if (that != null) {
            this.x = that.x;
            this.y = that.y;
            this.color = that.color;
        }
    }

    public abstract Shape clone();

    @Override
    public boolean equals(final Object o) {
        if (!(o instanceof Shape)) {
            return false;
        }
        final Shape that = (Shape) o;
        return that.x == this.x
            && that.y == this.y
            && that.color.equals(this.color);
    }
}
