package shapes;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.awt.Color;

import org.junit.Before;
import org.junit.Test;

import util.LatticePoint;

public class DotTest {
    private Dot dot;

    @Before
    public void setUp() {
        dot = new Dot(new LatticePoint(0, 5), Color.BLACK);
    }

    @Test
    public void testGetX() {
        assertEquals(-1, dot.getX());
    }

    @Test
    public void testGetY() {
        assertEquals(4, dot.getY());
    }

    @Test
    public void testIsInsideBounds() {
        /* way (-1, 1) has distance 1.41 */
        final LatticePoint p = new LatticePoint(-1, 6);

        assertTrue(dot.isInsideBounds(p));
    }

    @Test
    public void testIsNotInsideBounds() {
        /* way (-2, 1) has distance 2.24 */
        final LatticePoint p = new LatticePoint(-2, 6);

        assertFalse(dot.isInsideBounds(p));
    }

    @Test
    public void testPointOnBorderIsNotInsideBounds() {
        /* way (-2, 0) has distance 2 */
        final LatticePoint p = new LatticePoint(-2, 5);

        assertFalse(dot.isInsideBounds(p));
    }
}
