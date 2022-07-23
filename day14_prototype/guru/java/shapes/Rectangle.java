package shapes;

import shapes.Shape;

/// Another shape
public class Rectangle extends Shape {
    private int width;
    private int height;

    public Rectangle(final int width, final int height) {
        this.width = width;
        this.height = width;
    }

    public Rectangle(final Rectangle that) {
        super(that);
        if (that != null) {
            this.width = that.width;
            this.height = that.height;
        }
    }

    @Override
    public Rectangle clone() {
        return new Rectangle(this);
    }

    @Override
    public boolean equals(final Object o) {
        if(!(o instanceof Rectangle) || !super.equals(o)) {
            return false;
        }
        final Rectangle that = (Rectangle) o;
        return that.width == this.width && that.height == this.height;
    }
}
