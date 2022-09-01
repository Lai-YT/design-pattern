package shapes;

import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import util.LatticePoint;

public class CompoundShape extends BaseShape {
    private final List<Shape> children = new ArrayList<>();

    public CompoundShape(final Shape... children) {
        super(new LatticePoint(0, 0), Color.BLACK);
        add(children);
    }

    public void add(final Shape child) {
        children.add(child);
    }

    public void add(final Shape... children) {
        this.children.addAll(Arrays.asList(children));
    }

    public void remove(final Shape child) {
        children.remove(child);
    }

    public void remove(final Shape... children) {
        this.children.removeAll(Arrays.asList(children));
    }

    public void clear() {
        children.clear();
    }

    @Override
    public int getX() {
        if (children.isEmpty()) {
            return 0;
        }
        int minX = Integer.MAX_VALUE;
        for (final Shape child : children) {
            minX = Math.min(minX, child.getX());
        }
        return minX;
    }

    @Override
    public int getY() {
        if (children.isEmpty()) {
            return 0;
        }
        int minY = Integer.MAX_VALUE;
        for (final Shape child : children) {
            minY = Math.min(minY, child.getY());
        }
        return minY;
    }

    @Override
    public int getWidth() {
        int maxWidth = 0;
        final int leftX = getX();
        for (final Shape child : children) {
            final int rightX = child.getX() + child.getWidth();
            final int width = rightX - leftX;
            maxWidth = Math.max(maxWidth, width);
        }
        return maxWidth;
    }

    @Override
    public int getHeight() {
        int maxHeight = 0;
        final int upperY = getY();
        for (final Shape child : children) {
            final int lowerY = child.getY() + child.getHeight();
            final int height = lowerY - upperY;
            maxHeight = Math.max(maxHeight, height);
        }
        return maxHeight;
    }

    @Override
    public void drag() {
        for (final Shape child : children) {
            child.drag();
        }
    }

    @Override
    public void drop() {
        for (final Shape child : children) {
            child.drop();
        }
    }

    @Override
    public void moveTo(final LatticePoint point) {
        for (final Shape child : children) {
            child.moveTo(point);
        }
    }

    @Override
    public void moveBy(final LatticePoint delta) {
        for (final Shape child : children) {
            child.moveBy(delta);
        }
    }

    @Override
    public boolean isInsideBounds(final LatticePoint point) {
        for (final Shape child : children) {
            if (child.isInsideBounds(point)) {
                return true;
            }
        }
        return false;
    }

    @Override
    public void setColor(final Color color) {
        super.setColor(color);
        for (final Shape child : children) {
            child.setColor(color);
        }
    }

    @Override
    public void unSelect() {
        super.unSelect();
        for (final Shape child : children) {
            child.unSelect();
        }
    }

    public List<Shape> getChildAt(final LatticePoint point) {
        final List<Shape> childrenAtPoint = new ArrayList<>();
        for (final Shape child : children) {
            if (child.isInsideBounds(point)) {
                childrenAtPoint.add(child);
            }
        }
        return childrenAtPoint;
    }

    public void selectChildAt(final LatticePoint point) {
        for (final Shape child : getChildAt(point)) {
            child.select();
        }
    }

    public List<Shape> getSelected() {
        final List<Shape> childrenSelected = new ArrayList<>();
        for (final Shape child : children) {
            if (child.isSelected()) {
                childrenSelected.add(child);
            }
        }
        return childrenSelected;
    }

    @Override
    public void paint(final Graphics graphics) {
        if (isSelected()) {
            enableSelectionStyle(graphics);
            graphics.drawRect(getX() - 1, getY() - 1, getWidth() + 1, getHeight() + 1);
            disableSelectionStyle(graphics);
        }
        for (final Shape child : children) {
            child.paint(graphics);
        }
    }
}
