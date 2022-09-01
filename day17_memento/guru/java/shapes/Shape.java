package shapes;

import java.awt.*;
import java.io.Serializable;

import util.LatticePoint;

public interface Shape extends Serializable {
    /** The left-most x. */
    int getX();

    /** The upper-most y. */
    int getY();
    int getWidth();
    int getHeight();
    void drag();
    void drop();
    void moveTo(final LatticePoint point);
    void moveBy(final LatticePoint delta);

    /** On the boundary is also a false. */
    boolean isInsideBounds(final LatticePoint point);
    Color getColor();
    void setColor(final Color color);
    void select();
    void unSelect();
    boolean isSelected();
    void paint(final Graphics graphics);
}
