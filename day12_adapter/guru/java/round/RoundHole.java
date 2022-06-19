package round;

import round.RoundPeg;

/**
 * RoundHoles are compatiable with RoundPegs.
 */
public class RoundHole {
    private double radius;

    public RoundHole(final double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public boolean fits(final RoundPeg peg) {
        return this.getRadius() >= peg.getRadius();
    }
}
