package ui;

import java.awt.*;
import javax.swing.*;

public class UI {
    private final Player player;
    private final JTextField textField = new JTextField();  /* accessed in lambda */

    private interface StateButtonCallback {
        /* The signature is customized for the "on" methods of State. */
        String click();
    }

    public UI(final Player player) {
        this.player = player;
    }

    public void init() {
        final JFrame frame = new JFrame("Test player");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        frame.setSize(300, 100);
        /* NOTE: because of the temporal coupling,
            swing components aren't pulled up as fields */
        createContextWithButtons(frame);
    }

    private void createContextWithButtons(final JFrame frame) {
        final JPanel context = new JPanel();
        textField.setText("");
        context.add(textField);
        context.setLayout(new BoxLayout(context, BoxLayout.Y_AXIS));
        addButtons(context);
        frame.getContentPane().add(context);
    }

    private void addButtons(final JPanel context) {
        final JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));

        /* Context delegates handling user's input to a state object. Naturally,
         * the outcome will depend on what state is currently active, since all
         * states can handle the input differently.
         */
        buttonPanel.add(createButtonOfNameAndCallback("play", player::onPlay));
        buttonPanel.add(createButtonOfNameAndCallback("stop", player::onLock));
        buttonPanel.add(createButtonOfNameAndCallback("next", player::onNext));
        buttonPanel.add(createButtonOfNameAndCallback("prev", player::onPrev));

        context.add(buttonPanel);
    }

    private JButton createButtonOfNameAndCallback(final String name, final StateButtonCallback callback) {
        final JButton button = new JButton(name);
        button.addActionListener((e) -> {
            final String message = callback.click();
            textField.setText(message);
        });
        return button;
    }
}
