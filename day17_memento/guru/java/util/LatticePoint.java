package util;

import java.awt.Point;

public class LatticePoint {
    public final int x;
    public final int y;

    public LatticePoint(final int x, final int y) {
        this.x = x;
        this.y = y;
    }

    public LatticePoint(final LatticePoint p) {
        this(p.x, p.y);
    }

    /** A convenient support on conversion from java.awt.Point. */
    public LatticePoint(final Point p) {
        this(p.x, p.y);
    }

    public double distanceTo(final LatticePoint p) {
        return Math.hypot(p.x - this.x, p.y - this.y);
    }

    public LatticePoint wayTo(final LatticePoint p) {
        return new LatticePoint(p.x - this.x, p.y - this.y);
    }

    public LatticePoint plus(final LatticePoint p) {
        return new LatticePoint(this.x + p.x, this.y + p.y);
    }
}

