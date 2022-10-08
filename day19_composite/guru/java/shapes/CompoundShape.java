package shapes;

import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/** Consists of other shape objects. */
public class CompoundShape extends BaseShape {
    private final List<Shape> children = new ArrayList<>();

    public CompoundShape(final Shape... components) {
        super(0, 0, Color.BLACK);
        add(components);
    }

    public void add(final Shape component) {
        children.add(component);
    }

    public void add(final Shape... components) {
        children.addAll(Arrays.asList(components));
    }

    public void remove(final Shape component) {
        children.remove(component);
    }

    public void remove(final Shape... components) {
        children.removeAll(Arrays.asList(components));
    }

    public void clear() {
        children.clear();
    }

    @Override
    public int getX() {
        if (children.isEmpty()) {
            return 0;
        }
        int leftmostX = children.get(0).getX();
        for (final Shape child : children) {
            leftmostX = Math.min(leftmostX, child.getX());
        }
        return leftmostX;
    }

    @Override
    public int getY() {
        if (children.isEmpty()) {
            return 0;
        }
        int uppermostY = children.get(0).getY();
        for (final Shape child : children) {
            uppermostY = Math.min(uppermostY, child.getY());
        }
        return uppermostY;
    }

    @Override
    public int getWidth() {
        int maxWidth = 0;
        final int x = getX();
        for (final Shape child : children) {
            final int childRelativeX = child.getX() - x;
            maxWidth = Math.max(maxWidth, childRelativeX + child.getWidth());
        }
        return maxWidth;
    }

    @Override
    public int getHeight() {
        int maxHeight = 0;
        final int y = getY();
        for (final Shape child : children) {
            final int childRelativeY = child.getY() - y;
            maxHeight = Math.max(maxHeight, childRelativeY + child.getHeight());
        }
        return maxHeight;
    }

    @Override
    public void move(final int x, final int y) {
        for (final Shape child : children) {
            child.move(x, y);
        }
    }

    @Override
    public boolean isInsideBounds(final int x, final int y) {
        for (final Shape child : children) {
            if (child.isInsideBounds(x, y)) {
                return true;
            }
        }
        return false;
    }

    @Override
    public void unSelect() {
        super.unSelect();
        for (final Shape child : children) {
            child.unSelect();
        }
    }

    public void selectChildAt(final int x, final int y) {
        for (final Shape child : children) {
            if (child.isInsideBounds(x, y)) {
                child.select();
            }
        }
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
