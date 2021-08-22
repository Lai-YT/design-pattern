package language;

import language.CommandListNode;
import language.Context;
import language.ExecuteException;
import language.Node;
import language.ParseException;


/*
 * <program> ::= program <command list>
 */
public class ProgramNode extends Node {
    private CommandListNode commandListNode;

    @Override
    public void parse(final Context context) throws ParseException {
        context.skipToken("program");
        this.commandListNode = new CommandListNode();
        this.commandListNode.parse(context);
    }

    @Override
    public void execute() throws ExecuteException {
        this.commandListNode.execute();
    }

    /*
     * When a context is wrapped by [],
     * it is successfully interpreted by the interpreter.
     */
    @Override
    public String toString() {
        return "[program " + this.commandListNode + "]";
    }
}
