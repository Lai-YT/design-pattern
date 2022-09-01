import java.awt.Color;

import editor.Editor;
import shapes.Circle;
import shapes.CompoundShape;
import shapes.Dot;
import shapes.Rectangle;
import util.LatticePoint;

public class Main {
    public static void main(final String[] args) {
        final Editor editor = new Editor();
        editor.loadShapes(
                new Circle(new LatticePoint(10, 10), 10, Color.BLUE),
                new CompoundShape(
                        new Circle(new LatticePoint(110, 110), 50, Color.RED),
                        new Dot(new LatticePoint(160, 160), Color.RED)),
                new CompoundShape(
                        new Rectangle(new LatticePoint(250, 250), 100, 100, Color.GREEN),
                        new Dot(new LatticePoint(240, 240), Color.GREEN),
                        new Dot(new LatticePoint(240, 360), Color.GREEN),
                        new Dot(new LatticePoint(360, 360), Color.GREEN),
                        new Dot(new LatticePoint(360, 240), Color.GREEN)));
    }
}
