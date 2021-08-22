package turtle;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Point;
import language.ExecuteException;
import language.Executor;
import language.ExecutorFactory;


public class TurtleCanvas extends Canvas implements ExecutorFactory {
    final static int UNIT_LENGTH = 30;
    final static int DIRECTION_UP = 0;
    final static int DIRECTION_RIGHT = 3;
    final static int DIRECTION_DOWN = 6;
    final static int DIRECTION_LEFT = 9;
    final static int RELATIVE_DIRECTION_RIGHT = 3;
    final static int RELATIVE_DIRECTION_LEFT = -3;
    final static int RADIUS = 3;

    private int direction = 0;
    private Point position;

    public TurtleCanvas(final int width, final int height) {
        this.setSize(width, height);
        this.initialize();
    }

    public void initialize() {
        Dimension size = this.getSize();
        this.position = new Point(size.width / 2, size.height / 2);
        this.direction = 0;
        this.setForeground(Color.red);
        this.setBackground(Color.white);

        Graphics graph = this.getGraphics();
        if (graph != null) {
            graph.clearRect(0, 0, size.width, size.height);
        }
    }

    @Override
    public Executor createExecutor(final String command) {
        Executor executor;
        switch (command) {
            case "go":
                executor = new GoExecutor(this);
                break;
            case "right":
                executor = new DirectionExecutor(this, TurtleCanvas.RELATIVE_DIRECTION_RIGHT);
                break;
            case "left":
                executor = new DirectionExecutor(this, TurtleCanvas.RELATIVE_DIRECTION_LEFT);
                break;
            default:
                executor = null;
                break;
        }
        return executor;
    }

    void setRelativeDirection(final int relativeDirection) {
        this.setDirection(this.direction + relativeDirection);
    }

    void setDirection(int direction) {
        direction = direction < 0
                    ? 12 - (-direction) % 12
                    : direction % 12;
        this.direction = direction % 12;
    }

    void go(final int length) {
        int newX = this.position.x;
        int newY = this.position.y;

        switch (this.direction) {
            case TurtleCanvas.DIRECTION_UP:
                newY -= length;
                break;
            case TurtleCanvas.DIRECTION_RIGHT:
                newX += length;
                break;
            case TurtleCanvas.DIRECTION_DOWN:
                newY += length;
                break;
            case TurtleCanvas.DIRECTION_LEFT:
                newX -= length;
                break;
            default:
                break;
        }

        Graphics graph = this.getGraphics();
        if (graph != null) {
            graph.drawLine(this.position.x, this.position.y, newX, newY);
            graph.fillOval(
                newX - TurtleCanvas.RADIUS,
                newY - TurtleCanvas.RADIUS,
                TurtleCanvas.RADIUS * 2 + 1,
                TurtleCanvas.RADIUS * 2 + 1
            );
        }

        this.position.x = newX;
        this.position.y = newY;
    }
}


abstract class TurtleExecutor implements Executor {
    protected TurtleCanvas canvas;

    public TurtleExecutor(final TurtleCanvas canvas) {
        this.canvas = canvas;
    }

    @Override
    public abstract void execute();
}


class GoExecutor extends TurtleExecutor {
    public GoExecutor(final TurtleCanvas canvas) {
        super(canvas);
    }

    @Override
    public void execute() {
        this.canvas.go(TurtleCanvas.UNIT_LENGTH);
    }
}


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
