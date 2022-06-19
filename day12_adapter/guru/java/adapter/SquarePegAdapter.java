package adapter;

import round.RoundPeg;
import square.SquarePeg;

/**
 * Adapter allows fitting square pegs into round holes.
 */
public class SquarePegAdapter extends RoundPeg {
    public SquarePegAdapter(final SquarePeg peg) {
        /* Calculate a minimun circle radius, which can fit this peg. */
        super(Math.sqrt(2) * 0.5 * peg.getWidth());
    }
}
