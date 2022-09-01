package shapes;

import java.awt.*;

import util.LatticePoint;

// FIXME: what does drag, drop, moveTo and moveBy intend to do?

public abstract class BaseShape implements Shape {
    /** Does not have to be in the shape. */
    private LatticePoint upperleftRefPoint;
    private LatticePoint delta = new LatticePoint(0, 0);
    private Color color;
    private boolean selected = false;

    protected BaseShape(final LatticePoint upperleftRefPoint, final Color color) {
        this.upperleftRefPoint = upperleftRefPoint;
        this.color = color;
    }

    @Override
    public int getX() {
        return upperleftRefPoint.x;
    }

    @Override
    public int getY() {
        return upperleftRefPoint.y;
    }

    @Override
    public void drag() {
        delta = new LatticePoint(upperleftRefPoint);
    }

    @Override
    public void drop() {
        upperleftRefPoint = new LatticePoint(delta);
    }

    @Override
    public void moveBy(final LatticePoint delta) {
        upperleftRefPoint = upperleftRefPoint.plus(delta);
    }

    @Override
    public void moveTo(final LatticePoint point) {
        this.upperleftRefPoint = point.plus(delta);
    }

    /// The shape is considered to be bounded by an rectangle.
    @Override
    public boolean isInsideBounds(final LatticePoint point) {
        return point.x > this.upperleftRefPoint.x && point.x < this.upperleftRefPoint.x + getWidth()
                && point.y > this.upperleftRefPoint.y && point.y < this.upperleftRefPoint.y + getHeight();
    }

    @Override
    public Color getColor() {
        return color;
    }

    @Override
    public void setColor(final Color color) {
        this.color = color;
    }

    @Override
    public boolean isSelected() {
        return selected;
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
    public void paint(final Graphics graphics) {
        if (selected) {
            enableSelectionStyle(graphics);
        } else {
            disableSelectionStyle(graphics);
        }
    }

    protected void enableSelectionStyle(final Graphics graphics) {
        graphics.setColor(Color.LIGHT_GRAY);

        final float[] dash = { 2.0f };
        ((Graphics2D) graphics)
                .setStroke(new BasicStroke(1.0f, BasicStroke.CAP_BUTT, BasicStroke.JOIN_MITER, 2.0f, dash, 0));
    }

    protected void disableSelectionStyle(final Graphics graphics) {
        graphics.setColor(color);
        ((Graphics2D) graphics).setStroke(new BasicStroke());
    }
}
