package shapes;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.awt.Color;

import org.junit.Before;
import org.junit.Test;

import util.LatticePoint;

public class CircleTest {
    private Circle circle;

    @Before
    public void setUp() {
        circle = new Circle(new LatticePoint(10, 25), 5, Color.BLACK);
    }

    @Test
    public void testGetX() {
        assertEquals(5, circle.getX());
    }

    @Test
    public void testGetY() {
        assertEquals(20, circle.getY());
    }

    @Test
    public void testGetHeight() {
        assertEquals(10, circle.getHeight());
    }

    @Test
    public void testGetWidth() {
        assertEquals(10, circle.getWidth());
    }

    @Test
    public void testIsInsideBounds() {
        /* way (3, -3) has distance 4.24 */
        final LatticePoint p = new LatticePoint(13, 22);

        assertTrue(circle.isInsideBounds(p));
    }

    @Test
    public void testIsNotInsideBounds() {
        /* way (3, -5) has distance 5.83 */
        final LatticePoint p = new LatticePoint(13, 20);

        assertFalse(circle.isInsideBounds(p));
    }

    @Test
    public void testPointOnBorderIsNotInsideBounds() {
        /* way (3, -4) has distance 5 */
        final LatticePoint p = new LatticePoint(13, 21);

        assertFalse(circle.isInsideBounds(p));
    }
}
