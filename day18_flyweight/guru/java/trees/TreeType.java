package trees;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;

/// Contains state shared by serveral trees.
public class TreeType {
    private final String name;
    private final Color color;
    private final String otherTreeData;

    public TreeType(final String name, final Color color, final String otherTreeData) {
        this.name = name;
        this.color = color;
        this.otherTreeData = otherTreeData;
    }

    public void draw(final Graphics graphics, final Point point) {
        graphics.setColor(Color.BLACK);
        graphics.fillRect(point.x - 1, point.y, 3, 5);
        graphics.setColor(color);
        graphics.fillOval(point.x - 5, point.y - 10, 10, 10);
    }
}
