package shapes;

import shapes.Shape;

/// Simple shape
public class Circle extends Shape {
    private int radius;

    public Circle(final int radius) {
        this.radius = radius;
    }

    public Circle(final Circle that) {
        /* A parent constructor call is needed to copy private
            fields defined in the parent class. */
        super(that);
        if (that != null) {
            this.radius = that.radius;
        }
    }

    @Override
    public Circle clone() {
        return new Circle(this);
    }

    @Override
    public boolean equals(final Object o) {
        if (!(o instanceof Circle) || !super.equals(o)) {
            return false;
        }
        final Circle that = (Circle) o;
        return that.radius == this.radius;
    }
}
