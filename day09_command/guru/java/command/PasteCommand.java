package command;

import command.Command;
import editor.Editor;


/**
 * Paste text from clipboard.
 */
public class PasteCommand extends Command {
    public PasteCommand(final Editor editor) {
        super(editor);
    }

    @Override
    public boolean execute() {
        if (this.editor.clipboard == null || this.editor.clipboard.isEmpty()) {
            return false;
        }

        this.backup();
        this.editor.textField.insert(
                this.editor.clipboard, this.editor.textField.getCaretPosition());
        return true;
    }
}
