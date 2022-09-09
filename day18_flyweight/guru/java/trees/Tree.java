package trees;

import java.awt.Graphics;
import java.awt.Point;

// Contains state unique for each tree.
public class Tree {
    private final Point point;
    private final TreeType type;

    public Tree(final Point point, final TreeType type) {
        this.point = point;
        this.type = type;
    }

    public void draw(final Graphics graphics) {
        type.draw(graphics, point);
    }
}
