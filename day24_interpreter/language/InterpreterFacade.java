package language;

import language.Context;
import language.ExecutorFactory;
import language.ParseException;
import language.ProgramNode;


public class InterpreterFacade {
    private ExecutorFactory factory;
    private Context context;
    private ProgramNode programNode;

    public InterpreterFacade(final ExecutorFactory factory) {
        this.factory = factory;
    }

    public boolean parse(final String text) {
        this.context = new Context(text);
        this.context.setExecutorFactory(this.factory);
        this.programNode = new ProgramNode();

        try {
            this.programNode.parse(this.context);
            System.out.println(this.programNode);
        } catch (final ParseException e) {
            System.out.println(e);
            return false;
        }
        return true;
    }

    public boolean execute() {
        try {
            this.programNode.execute();
        } catch (final ExecuteException e) {
            System.out.println(e);
            return false;
        }
        return true;
    }
}
