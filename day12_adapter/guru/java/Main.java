import adapter.SquarePegAdapter;
import round.RoundHole;
import round.RoundPeg;
import square.SquarePeg;

/**
 * Somewhere in client code...
 */
public class Main {
    public static void main(String[] args) {
        final RoundHole hole = new RoundHole(5);

        final RoundPeg rpeg = new RoundPeg(5);
        /* Round fits round, no surprise. */
        if (hole.fits(rpeg)) {
            System.out.println("Round reg with radius 5 fits round hole with width 5.");
        }

        final SquarePeg smallSqPeg = new SquarePeg(2);
        final SquarePeg largeSqPeg = new SquarePeg(20);
        // hole.fits(smallSqPeg);  /* Won't compile. */

        /* Adapter solves the problem. */
        SquarePegAdapter smallSqAdapter = new SquarePegAdapter(smallSqPeg);
        SquarePegAdapter largeSqAdapter = new SquarePegAdapter(largeSqPeg);
        if (hole.fits(smallSqAdapter)) {
            System.out.println("Square peg with width 2 fits round hole with radius 5.");
        }
        if (!hole.fits(largeSqAdapter)) {
            System.out.println("Square peg with width 20 does not fit into round hole with radius 5.");
        }
    }
}
