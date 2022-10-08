import java.awt.Color;

import editor.ImageEditor;
import shapes.Circle;
import shapes.CompoundShape;
import shapes.Dot;
import shapes.Rectangle;

public class Main {
    public static void main(final String[] args) {
        final ImageEditor editor = new ImageEditor();
        editor.loadShapes(
            new Circle(30, 30, 20, Color.BLUE),
            new CompoundShape(
                new Circle(110, 110, 50, Color.RED),
                new Dot(160, 160, Color.RED)
            ),
            new CompoundShape(
                new Rectangle(250, 250, 100, 100, Color.GREEN),
                new Dot(240, 240, Color.GREEN),
                new Dot(240, 360, Color.GREEN),
                new Dot(360, 360, Color.GREEN),
                new Dot(360, 240, Color.GREEN)
            ),
            new Rectangle(240, 30, 100, 30, Color.MAGENTA),
            new Circle(100, 120, 20, Color.BLACK)
        );
    }
}
