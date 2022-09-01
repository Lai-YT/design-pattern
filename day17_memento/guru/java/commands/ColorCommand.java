package commands;

import java.awt.*;

import editor.Editor;
import shapes.Shape;

/// Changes color of selected shape.
public class ColorCommand implements Command {
    private final Editor editor;
    private Color color;

    public ColorCommand(final Editor editor, final Color color) {
        this.editor = editor;
        this.color = color;
    }

    @Override
    public String getName() {
        return String.format("Colorize: %s", color.toString());
    }

    @Override
    public void execute() {
        for (final Shape child : editor.getShapes().getSelected()) {
            child.setColor(color);
        }
    }
}
