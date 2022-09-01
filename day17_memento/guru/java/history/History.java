package history;

import java.util.ArrayList;
import java.util.List;

import commands.Command;

/// Stores Commands and Mementos.
public class History {
    private List<Pair> history = new ArrayList<>();
    private int virtualSize = 0;

    private class Pair {
        final Command command;
        final Memento memento;

        Pair(final Command command, final Memento memento) {
            this.command = command;
            this.memento = memento;
        }
    }

    public void push(final Command command, final Memento memento) {
        if (virtualSize != history.size() && virtualSize > 0) {
            history = history.subList(0, virtualSize - 1);
        }
        history.add(new Pair(command, memento));
        virtualSize = history.size();
    }

    public void undo() {
        final Pair pair = getUndoOrNull();
        if (pair != null) {
            System.out.format("Undoing: %s", pair.command.getName());
            pair.memento.restore();
        }
    }

    private Pair getUndoOrNull() {
        if (virtualSize == 0) {
            return null;
        }
        virtualSize = Math.max(0, virtualSize - 1);
        return history.get(virtualSize);
    }

    public void redo() {
        final Pair pair = getRedoOrNull();
        if (pair != null) {
            System.out.format("Redoing: %d", pair.command.getName());
            pair.memento.restore();
            pair.command.execute();
        }
    }

    private Pair getRedoOrNull() {
        if (virtualSize == history.size()) {
            return null;
        }
        virtualSize = Math.min(history.size(), virtualSize + 1);
        return history.get(virtualSize - 1);
    }
}
