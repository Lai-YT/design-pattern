package shapes;

import java.awt.Color;
import java.awt.Graphics;

public class Dot extends BaseShape {
    private final int DOT_SIZE = 3;

    public Dot(final int x, final int y, final Color color) {
        super(x, y, color);
    }

    @Override
    public int getHeight() {
        return DOT_SIZE;
    }

    @Override
    public int getWidth() {
        return DOT_SIZE;
    }

    @Override
    public void paint(final Graphics graphics) {
        super.paint(graphics);
        graphics.fillRect(getX() - 1, getY() - 1, getWidth(), getHeight());
    }
}
