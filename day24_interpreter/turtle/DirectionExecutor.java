package turtle;

import turtle.TurtleCanvas;
import turtle.TurtleExecutor;


class DirectionExecutor extends TurtleExecutor {
    private int relativeDirection;

    public DirectionExecutor(final TurtleCanvas canvas, final int relativeDirection) {
        super(canvas);
        this.relativeDirection = relativeDirection;
    }

    @Override
    public void execute() {
        this.canvas.setRelativeDirection(this.relativeDirection);
    }
}
