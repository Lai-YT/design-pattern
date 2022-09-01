package editor;

import java.util.List;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;

import commands.ColorCommand;
import commands.MoveCommand;
import shapes.Shape;
import util.LatticePoint;

// FIXME: the shapes can't be moved.

public class Canvas extends java.awt.Canvas {
    private static final int PADDING = 10;
    private final Editor editor;
    private JFrame frame;

    public Canvas(final Editor editor) {
        this.editor = editor;
        createFrame();
        attachKeyboardListeners();
        attachMouseListeners();
        refresh();
    }

    private void createFrame() {
        frame = new JFrame();
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);

        createContentPanel(frame);
        frame.setVisible(true);
    }

    private void createContentPanel(final JFrame frame) {
        final JPanel contentPanel = new JPanel();
        contentPanel.setBorder(
                BorderFactory.createEmptyBorder(PADDING, PADDING, PADDING, PADDING));
        contentPanel.setLayout(new BoxLayout(contentPanel, BoxLayout.Y_AXIS));
        addHints(contentPanel);
        contentPanel.add(this);
        contentPanel.setBackground(Color.LIGHT_GRAY);
        frame.setContentPane(contentPanel);
    }

    private void addHints(final JPanel contentPanel) {
        final String[] hints = {
                "Select and drag to move.",
                "Right click to change color.",
                "Undo: Ctrl+Z, Redo: Ctrl+Y",
        };
        for (final String hint : hints) {
            contentPanel.add(new JLabel(hint), BorderLayout.PAGE_END);
        }
    }

    private void attachKeyboardListeners() {
        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(final KeyEvent e) {
                if ((e.getModifiersEx() & KeyEvent.CTRL_DOWN_MASK) != 0) {
                    switch (e.getKeyCode()) {
                        case KeyEvent.VK_Z:
                            editor.undo();
                            break;
                        case KeyEvent.VK_Y:
                            editor.redo();
                            break;
                        default:
                            break;
                    }
                }
            }
        });
    }

    private void attachMouseListeners() {
        final MouseAdapter colorizer = new MouseAdapter() {
            @Override
            public void mousePressed(final MouseEvent e) {
                if (e.getButton() == MouseEvent.BUTTON3) {
                    final List<Shape> shapesClicked = editor.getShapes()
                            .getChildAt(new LatticePoint(e.getPoint()));
                    if (!shapesClicked.isEmpty()) {
                        editor.execute(new ColorCommand(editor, new Color((int) (Math.random() * 0x1000000))));
                        repaint();
                    }
                }
            }
        };
        addMouseListener(colorizer);

        final MouseAdapter selector = new MouseAdapter() {
            @Override
            public void mousePressed(final MouseEvent e) {
                if (e.getButton() == MouseEvent.BUTTON1) {
                    final List<Shape> shapesClicked = editor.getShapes()
                            .getChildAt(new LatticePoint(e.getPoint()));
                    final boolean ctrl = (e.getModifiersEx() & ActionEvent.CTRL_MASK) == ActionEvent.CTRL_MASK;
                    if (!shapesClicked.isEmpty()) {
                        if (!ctrl) {
                            editor.getShapes().unSelect();
                        }
                    } else {
                        if (ctrl) {
                            for (final Shape shape : shapesClicked) {
                                if (shape.isSelected()) {
                                    shape.unSelect();
                                } else {
                                    shape.select();
                                }
                            }
                        } else {
                            /* If any of the targets are not selected,
                                unselect all of the shapes and only select the targets. */
                            for (final Shape shape : shapesClicked) {
                                if (!shape.isSelected()) {
                                    editor.getShapes().unSelect();
                                    break;
                                }
                            }
                            for (final Shape shape : shapesClicked) {
                                shape.select();
                            }
                        }
                    }
                }
                repaint();
            }
        };
        addMouseListener(selector);

        final MouseAdapter dragger = new MouseAdapter() {
            private MoveCommand moveCommand;

            @Override
            public void mouseDragged(final MouseEvent e) {
                if ((e.getModifiersEx() & MouseEvent.BUTTON1_DOWN_MASK) == MouseEvent.BUTTON1_DOWN_MASK) {
                    final LatticePoint mousePos = new LatticePoint(e.getPoint());
                    if (moveCommand == null) {
                        moveCommand = new MoveCommand(editor);
                        moveCommand.start(mousePos);
                    }
                    moveCommand.move(mousePos);
                    repaint();
                }
            }

            @Override
            public void mouseReleased(final MouseEvent e) {
                if (e.getButton() == MouseEvent.BUTTON1 && moveCommand != null) {
                    moveCommand.stop(new LatticePoint(e.getPoint()));
                    editor.execute(moveCommand);
                    moveCommand = null;
                    repaint();
                }
            }
        };
        addMouseListener(dragger);
        addMouseMotionListener(dragger);
    }

    public int getWidth() {
        return editor.getShapes().getX() + editor.getShapes().getWidth() + PADDING;
    }

    public int getHeight() {
        return editor.getShapes().getY() + editor.getShapes().getHeight() + PADDING;
    }

    void refresh() {
        setSize(getWidth(), getHeight());
        frame.pack();
    }

    public void update(final Graphics graphics) {
        paint(graphics);
    }

    public void paint(final Graphics graphics) {
        final BufferedImage buffer = new BufferedImage(getWidth(), getHeight(), BufferedImage.TYPE_INT_RGB);
        final Graphics2D graphics2d = buffer.createGraphics();
        graphics2d.setBackground(Color.WHITE);
        graphics2d.clearRect(0, 0, getWidth(), getHeight());

        editor.getShapes().paint(buffer.getGraphics());
        graphics.drawImage(buffer, 0, 0, null);
    }

}
