package shapes;

import java.awt.Color;
import java.awt.Graphics;

import util.LatticePoint;

public class Dot extends BaseShape {
    public static final int DOT_SIZE = 2;
    private LatticePoint center;

    public Dot(final LatticePoint center, final Color color) {
        super(new LatticePoint(center.x - DOT_SIZE / 2, center.y - DOT_SIZE / 2), color);
        this.center = center;
    }

    @Override
    public int getWidth() {
        return DOT_SIZE;
    }

    @Override
    public int getHeight() {
        return DOT_SIZE;
    }

    @Override
    public void paint(final Graphics graphics) {
        super.paint(graphics);
        graphics.fillRect(getX() - 1, getY() - 1, getWidth(), getHeight());
    }

    @Override
    public boolean isInsideBounds(final LatticePoint point) {
        return point.distanceTo(center) < DOT_SIZE;
    }
}
