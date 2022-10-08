package shapes;

import java.awt.Color;
import java.awt.Graphics;

public class Circle extends BaseShape {
    private final int radius;

    public Circle(final int x, final int y, final int radius, final Color color) {
        super(x, y, color);
        this.radius = radius;
    }

    @Override
    public int getWidth() {
        return radius * 2;
    }

    @Override
    public int getHeight() {
        return radius * 2;
    }

    @Override
    public void paint(final Graphics graphics) {
        super.paint(graphics);
        graphics.drawOval(getX(), getY(), getWidth() - 1, getHeight() - 1);
    }
}
