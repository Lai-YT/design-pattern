package shapes;

import static org.junit.Assert.assertEquals;

import java.awt.Color;

import org.junit.Before;
import org.junit.Test;

import util.LatticePoint;

/** Test the default implementations. */
public class BaseShapeTest {
    private BaseShape shape;

    @Before
    public void setUp() {
        shape = new BaseShape(new LatticePoint(10, 15), Color.BLACK) {
            @Override
            public int getWidth() {
                // Auto-generated method stub
                return 0;
            }

            @Override
            public int getHeight() {
                // Auto-generated method stub
                return 0;
            }
        };
    }

    @Test
    public void testDrag() {

    }

    @Test
    public void testDrop() {

    }

    @Test
    public void testMoveBy() {
        final LatticePoint delta = new LatticePoint(25, 30);

        shape.moveBy(delta);

        assertEquals(35, shape.getX());
        assertEquals(45, shape.getY());
    }


    @Test
    public void testMoveTo() {
        final LatticePoint dest = new LatticePoint(25, 30);

        shape.moveTo(dest);

        assertEquals(dest.x, shape.getX());
        assertEquals(dest.y, shape.getY());
    }
}
