package shapes;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.awt.Color;

import org.junit.Before;
import org.junit.Test;

import util.LatticePoint;

public class RectangleTest {
    private Rectangle rect;

    @Before
    public void setUp() {
        rect = new Rectangle(new LatticePoint(5, 15), 200, 50, Color.black);
    }

    @Test
    public void testIsInsideBounds() {
        final LatticePoint p = new LatticePoint(100, 50);

        assertTrue(rect.isInsideBounds(p));
    }

    @Test
    public void testPointAboveIsNotInsideBounds() {
        final LatticePoint pointAbove = new LatticePoint(10, 5);

        assertFalse(rect.isInsideBounds(pointAbove));
    }

    @Test
    public void testPointOnLeftIsNotInsideBounds() {
        final LatticePoint pointOnLeft = new LatticePoint(4, 50);

        assertFalse(rect.isInsideBounds(pointOnLeft));
    }

    @Test
    public void testPointOnBorderIsNotInsideBounds() {
        final LatticePoint lowerRightCorner = new LatticePoint(205, 65);

        assertFalse(rect.isInsideBounds(lowerRightCorner));
    }
}
