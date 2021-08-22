package language;

import java.util.Set;
import language.Context;
import language.ExecuteException;
import language.Executor;
import language.Node;
import language.ParseException;


/*
 * <primitive command> ::= go | right | left
 */
public class PrimitiveCommandNode extends Node {
    public static final Set<String> COMMANDS = Set.of("go", "right", "left");
    
    private String command;
    private Executor executor;

    @Override
    public void parse(final Context context) throws ParseException {
        this.command = context.currentToken();
        context.skipToken(this.command);
        this.executor = context.createExecutor(this.command);
    }

    @Override
    public void execute() throws ExecuteException {
        if (executor == null) {
            throw new ExecuteException(this.command + ": is not defined");
        }
        this.executor.execute();
    }

    @Override
    public String toString() {
        return this.command;
    }
}
