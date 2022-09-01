package shapes;

import java.awt.Color;
import java.awt.Graphics;

import util.LatticePoint;

public class Rectangle extends BaseShape {
    private final int width;
    private final int height;

    public Rectangle(
            final LatticePoint upperLeft, final int width, final int height, final Color color) {
        super(upperLeft, color);
        this.width = width;
        this.height = height;
    }

    @Override
    public int getWidth() {
        return width;
    }

    @Override
    public int getHeight() {
        return height;
    }

    @Override
    public void paint(final Graphics graphics) {
        super.paint(graphics);
        graphics.drawRect(getX(), getY(), getWidth() - 1, getHeight() - 1);
    }
}
