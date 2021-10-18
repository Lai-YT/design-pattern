package turtle;

import turtle.TurtleCanvas;
import turtle.TurtleExecutor;


class GoExecutor extends TurtleExecutor {
    public GoExecutor(final TurtleCanvas canvas) {
        super(canvas);
    }

    @Override
    public void execute() {
        this.canvas.go(TurtleCanvas.UNIT_LENGTH);
    }
}
