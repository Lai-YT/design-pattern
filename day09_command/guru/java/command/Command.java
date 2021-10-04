package command;

import editor.Editor;


/**
 * Abstract base command.
 */
public abstract class Command {
    public Editor editor;
    private String backup;

    Command(final Editor editor) {
        this.editor = editor;
    }

    void backup() {
        this.backup = this.editor.textField.getText();
    }

    public void undo() {
        this.editor.textField.setText(this.backup);
    }

    public abstract boolean execute();
}
