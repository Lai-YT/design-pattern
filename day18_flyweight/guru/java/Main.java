import java.awt.Color;
import java.awt.Point;

import forest.Forest;
import trees.Tree;
import trees.TreeFactory;
import trees.TreeType;

public class Main {
    private static final int CANVAS_SIZE = 600;
    private static final int TREES_TO_DRAW = 3_000;
    private static final int TREE_TYPES = 3;

    public static void main(final String[] args) {
        final Forest forest = new Forest();
        for (int i = 0; i < TREES_TO_DRAW / TREE_TYPES; ++i) {
            forest.plantTree(new Point(random(CANVAS_SIZE), random(CANVAS_SIZE)),
                "Summer Oak", Color.GREEN, "Oak texture stub");
            forest.plantTree(new Point(random(CANVAS_SIZE), random(CANVAS_SIZE)),
                "Autumn Oak", Color.ORANGE, "Autumn oak texture stub");
            forest.plantTree(new Point(random(CANVAS_SIZE), random(CANVAS_SIZE)),
                "Cherry tree", Color.PINK, "Cherry tree texture stub");
        }
        forest.setSize(CANVAS_SIZE, CANVAS_SIZE);
        forest.setVisible(true);

        printApproxMemUsage();
    }

    private static int random(final int max) {
        final int min = 0;
        return random(min, max);
    }

    private static int random(final int min, final int max) {
        return min + (int) (Math.random() * (max - min + 1));
    }

    private static void printApproxMemUsage() {
        System.out.println(TREES_TO_DRAW + " trees drawn");
        System.out.println("---------------------");
        System.out.println("Memory usage:");
        System.out.println("Tree size (8 bytes) * " + TREES_TO_DRAW);
        System.out.println("+ TreeType size (~30 bytes) * " + TREE_TYPES);
        System.out.println("---------------------");
        System.out.println("Total: " + ((TREES_TO_DRAW * 8 + TREE_TYPES * 30) / 1024)
                + " KB (instead of " + ((TREES_TO_DRAW * (8 + 30)) / 1024) + " KB)");
    }
}
