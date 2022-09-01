package editor;

import javax.swing.*;
import java.io.*;
import java.util.Base64;

import commands.Command;
import history.History;
import history.Memento;
import shapes.CompoundShape;
import shapes.Shape;

public class Editor extends JComponent {
    private final Canvas canvas;
    private CompoundShape shapes = new CompoundShape();
    private final History history = new History();

    public Editor() {
        canvas = new Canvas(this);
    }

    public void loadShapes(final Shape... shapes) {
        this.shapes.clear();
        this.shapes.add(shapes);
        canvas.refresh();
    }

    public CompoundShape getShapes() {
        return shapes;
    }

    public void execute(final Command command) {
        history.push(command, new Memento(this));
        command.execute();
    }

    public void undo() {
        history.undo();
        canvas.repaint();
    }

    public void redo() {
        history.redo();
        canvas.repaint();
    }

    public String backup() {
        try (final ByteArrayOutputStream baos = new ByteArrayOutputStream();
                final ObjectOutputStream oos = new ObjectOutputStream(baos)) {
            oos.writeObject(this.shapes);
            return Base64.getEncoder().encodeToString(baos.toByteArray());
        } catch (final IOException e) {
            return "";
        }
    }

    public void restore(final String state) {
        final byte[] data = Base64.getDecoder().decode(state);
        try (final ByteArrayInputStream bais = new ByteArrayInputStream(data);
                final ObjectInputStream ois = new ObjectInputStream(bais)) {
            shapes = (CompoundShape) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
