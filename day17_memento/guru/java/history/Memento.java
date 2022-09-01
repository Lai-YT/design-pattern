package history;

import editor.Editor;

public class Memento {
    private final String backup;
    private final Editor editor;

    public Memento(final Editor editor) {
        this.editor = editor;
        this.backup = editor.backup();
    }

    public void restore() {
        editor.restore(backup);
    }
}
