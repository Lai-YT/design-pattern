package button;

import javax.swing.SwingConstants;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import button.Button;

/**
 * Windows button implementation.
 */
public class WindowsButton implements Button {
    private final JPanel panel = new JPanel();
    private final JFrame frame = new JFrame();
    private JButton button;

    @Override
    public void render() {
        this.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        final JLabel label = new JLabel("Hello World!");
        label.setOpaque(true);
        label.setBackground(new Color(235, 233, 126));
        label.setFont(new Font("Dialog", Font.BOLD, 44));
        label.setHorizontalAlignment(SwingConstants.CENTER);
        this.panel.add(label);

        this.panel.setLayout(new FlowLayout(FlowLayout.CENTER));
        this.frame.getContentPane().add(this.panel);
        this.onClick();
        this.panel.add(this.button);

        this.frame.setSize(320, 200);
        this.frame.setVisible(true);
        this.onClick();
    }

    @Override
    public void onClick() {
        this.button = new JButton("Exit");
        this.button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(final ActionEvent e) {
                /* access outer class variable */
                WindowsButton.this.frame.setVisible(false);
                System.exit(0);
            }
        });
    }
}
