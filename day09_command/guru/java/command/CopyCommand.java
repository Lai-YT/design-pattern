package command;

import command.Command;
import editor.Editor;


/**
 * Copy selected text to clipboard.
 */
public class CopyCommand extends Command {
    public CopyCommand(final Editor editor) {
        super(editor);
    }

    @Override
    public boolean execute() {
        this.editor.clipboard = this.editor.textField.getSelectedText();
        return false;
    }
}
