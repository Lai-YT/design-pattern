package forest;

import javax.swing.JFrame;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.util.ArrayList;
import java.util.List;

import trees.Tree;
import trees.TreeFactory;
import trees.TreeType;

/// Which we draw.
public class Forest extends JFrame {
    private final List<Tree> trees = new ArrayList<>();

    public void plantTree(final Point point, final String name,
            final Color color, final String otherTreeData) {
        final TreeType type = TreeFactory.getTreeType(name, color, otherTreeData);
        final Tree tree = new Tree(point, type);
        trees.add(tree);
    }

    @Override
    public void paint(final Graphics graphics) {
        for (final Tree tree : trees) {
            tree.draw(graphics);
        }
    }
}
