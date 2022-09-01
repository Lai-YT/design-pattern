package util;

import org.junit.Test;

import static org.junit.Assert.assertEquals;
import org.junit.Before;

public class LatticePointTest {
    private LatticePoint a;
    private LatticePoint b;

    @Before
    public void setUp() {
        a = new LatticePoint(10, 100);
        b = new LatticePoint(30, 20);
    }

    @Test
    public void testDistanceTo() {
        final double actual = a.distanceTo(b);

        assertEquals(82.46, actual, 0.01);
    }

    @Test
    public void testPlus() {
        final LatticePoint actual = a.plus(b);

        assertEquals(40, actual.x);
        assertEquals(120, actual.y);
    }

    @Test
    public void testWayTo() {
        final LatticePoint actual = a.wayTo(b);

        assertEquals(20, actual.x);
        assertEquals(-80, actual.y);
    }
}
