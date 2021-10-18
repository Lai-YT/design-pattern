package turtle;

import language.Executor;
import turtle.TurtleCanvas;


abstract class TurtleExecutor implements Executor {
    protected TurtleCanvas canvas;

    public TurtleExecutor(final TurtleCanvas canvas) {
        this.canvas = canvas;
    }

    @Override
    public abstract void execute();
}
