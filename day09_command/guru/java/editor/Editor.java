package editor;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.WindowConstants;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import command.Command;
import command.CommandHistory;
import command.CopyCommand;
import command.CutCommand;
import command.PasteCommand;


/**
 * GUI of text editor.
 */
public class Editor {
    public JTextArea textField;
    public String clipboard;
    private CommandHistory history = new CommandHistory();

    public void init() {
        JFrame frame = new JFrame("Text editor (type & use buttons)");
        JPanel content = new JPanel();
        frame.setContentPane(content);
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        content.setLayout(new BoxLayout(content, BoxLayout.Y_AXIS));
        this.textField = new JTextArea();
        this.textField.setLineWrap(true);
        content.add(this.textField);

        JPanel buttons = new JPanel(new FlowLayout(FlowLayout.CENTER));
        JButton ctrlC = new JButton("Ctrl+C");
        ctrlC.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(final ActionEvent e) {
                Editor.this.executeCommand(new CopyCommand(Editor.this));
            }
        });
        buttons.add(ctrlC);
        JButton ctrlX = new JButton("Ctrl+X");
        ctrlX.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(final ActionEvent e) {
                Editor.this.executeCommand(new CutCommand(Editor.this));
            }
        });
        buttons.add(ctrlX);
        JButton ctrlV = new JButton("Ctrl+V");
        ctrlV.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(final ActionEvent e) {
                Editor.this.executeCommand(new PasteCommand(Editor.this));
            }
        });
        buttons.add(ctrlV);
        JButton ctrlZ = new JButton("Ctrl+Z");
        ctrlZ.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(final ActionEvent e) {
                Editor.this.undo();
            }
        });
        buttons.add(ctrlZ);
        content.add(buttons);

        frame.setSize(450, 200);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

    private void executeCommand(final Command command) {
        if (command.execute()) {
            this.history.push(command);
        }
    }

    private void undo() {
        if (this.history.isEmpty()) {
            return;
        }

        final Command command = this.history.pop();
        if (command != null) {
            command.undo();
        }
    }
}
