package commands;

import editor.Editor;
import shapes.Shape;
import util.LatticePoint;

public class MoveCommand implements Command {
    private final Editor editor;
    private LatticePoint startPoint;
    private LatticePoint endPoint;

    public MoveCommand(final Editor editor) {
        this.editor = editor;
    }

    @Override
    public String getName() {
        final LatticePoint way = startPoint.wayTo(endPoint);
        return String.format("Move by (x: %d, y: %d)", way.x, way.y);
    }

    public void start(final LatticePoint point) {
        startPoint = point;
        for (final Shape child : editor.getShapes().getSelected()) {
            child.drag();
        }
    }

    public void move(final LatticePoint point) {
        final LatticePoint way = startPoint.wayTo(point);
        for (final Shape child : editor.getShapes().getSelected()) {
            child.moveTo(way);
        }
    }

    public void stop(final LatticePoint point) {
        endPoint = point;
        for (final Shape child : editor.getShapes().getSelected()) {
            child.drop();
        }
    }

    @Override
    public void execute() {
        final LatticePoint way = startPoint.wayTo(endPoint);
        for (final Shape child : editor.getShapes().getSelected()) {
            child.moveBy(way);
        }
    }
}
