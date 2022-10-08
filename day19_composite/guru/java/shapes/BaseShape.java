package shapes;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

abstract class BaseShape implements Shape {
    private int x;
    private int y;
    private final Color color;
    private boolean selected = false;

    BaseShape(final int x, final int y, final Color color) {
        this.x = x;
        this.y = y;
        this.color = color;
    }

    @Override
    public int getX() {
        return x;
    }

    @Override
    public int getY() {
        return y;
    }

    @Override
    public int getHeight() {
        return 0;
    }

    @Override
    public int getWidth() {
        return 0;
    }

    @Override
    public void move(final int x, final int y) {
        this.x += x;
        this.y += y;
    }

    @Override
    public boolean isInsideBounds(final int x, final int y) {
        return x > this.x && x < (this.x + getWidth())
                && y > this.y && y < (this.y + getHeight());
    }

    @Override
    public void select() {
        selected = true;
    }

    @Override
    public void unSelect() {
        selected = false;
    }

    @Override
    public boolean isSelected() {
        return selected;
    }

    @Override
    public void paint(final Graphics graphics) {
        if (selected) {
            enableSelectionStyle(graphics);
        } else {
            disableSelectionStyle(graphics);
        }
    }

    protected void enableSelectionStyle(final Graphics graphics) {
        graphics.setColor(Color.LIGHT_GRAY);
        final Graphics2D g2 = (Graphics2D) graphics;
        final float[] dash = {2.0f};
        g2.setStroke(new BasicStroke(1.0f, BasicStroke.CAP_BUTT, BasicStroke.JOIN_MITER, 2.0f, dash, 0.0f));
    }

    protected void disableSelectionStyle(final Graphics graphics) {
        graphics.setColor(color);
        final Graphics2D g2 = (Graphics2D) graphics;
        g2.setStroke(new BasicStroke());
    }
}
