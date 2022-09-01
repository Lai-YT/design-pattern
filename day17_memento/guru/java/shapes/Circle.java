package shapes;

import java.awt.Color;
import java.awt.Graphics;

import util.LatticePoint;

public class Circle extends BaseShape {
    private final LatticePoint center;
    private final int radius;

    public Circle(final LatticePoint center, final int radius, final Color color) {
        super(new LatticePoint(center.x - radius, center.y - radius), color);
        this.center = center;
        this.radius = radius;
    }

    /** The diameter. */
    @Override
    public int getWidth() {
        return radius * 2;
    }

    /** The diameter. */
    @Override
    public int getHeight() {
        return getWidth();
    }

    @Override
    public void paint(final Graphics graphics) {
        super.paint(graphics);
        graphics.drawOval(getX(), getY(), getWidth() - 1, getHeight() - 1);
    }

    @Override
    public boolean isInsideBounds(final LatticePoint point) {
        return point.distanceTo(center) < radius;
    }
}
