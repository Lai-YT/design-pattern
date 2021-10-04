package command;

import command.Command;
import editor.Editor;


/**
 * Cut text to clipboard.
 */
public class CutCommand extends Command {
    public CutCommand(final Editor editor) {
        super(editor);
    }

    @Override
    public boolean execute() {
        final String selectedText = this.editor.textField.getSelectedText();
        if (selectedText == null || selectedText.isEmpty()) {
            return false;
        }

        this.backup();
        final String source = this.editor.textField.getText();
        this.editor.clipboard = selectedText;
        this.editor.textField.setText(this.cutString(source));
        return true;
    }

    private String cutString(final String source) {
        final String start = source.substring(0, this.editor.textField.getSelectionStart());
        final String end = source.substring(this.editor.textField.getSelectionEnd());
        return start + end;
    }
}
