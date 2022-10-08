package shapes;

import java.awt.Color;
import java.awt.Graphics;

public class Rectangle extends BaseShape {
    private final int width;
    private final int height;

    public Rectangle(final int x, final int y, final int width, final int height, final Color color) {
        super(x, y, color);
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
        graphics.drawRect(getX(), getY(), width - 1, height - 1);
    }
}
