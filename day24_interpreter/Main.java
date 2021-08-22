import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import language.InterpreterFacade;
import turtle.TurtleCanvas;


public class Main extends Frame implements ActionListener {
    private TurtleCanvas canvas = new TurtleCanvas(400, 400);
    private InterpreterFacade facade = new InterpreterFacade(this.canvas);
    private TextField programTextField = new TextField(
        "program repeat 3 go right go left end end"
    );

    public static void main(String[] args) {
        new Main("Interpreter Pattern Sample");
    }

    public Main(final String title) {
        super(title);
        this.setLayout(new BorderLayout());
        this.programTextField.addActionListener(this);
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(final WindowEvent event) {
                System.exit(0);
            }
        });
        this.add(this.programTextField, BorderLayout.NORTH);
        this.add(this.canvas, BorderLayout.CENTER);
        this.pack();
        this.setVisible(true);
        this.parseAndExecute();
    }

    @Override   /* method of ActionListener */
    public void actionPerformed(final ActionEvent event) {
        if (event.getSource().equals(this.programTextField)) {
            this.parseAndExecute();
        }
    }

    @Override  /* method of Frame */
    public void paint(final Graphics graph) {
        this.canvas.initialize();
        this.facade.execute();
    }

    private void parseAndExecute() {
        final String programText = this.programTextField.getText();
        System.out.println("programText = " + programText);
        facade.parse(programText);
        this.repaint();
    }
}
