package language;

import language.CommandListNode;
import language.Context;
import language.Node;
import language.ParseException;


/*
 * <program> ::= program <command list> end
 */
public class ProgramNode extends Node {
    private CommandListNode commandListNode;

    @Override
    public void parse(final Context context) throws ParseException {
        context.skipToken("program");
        this.commandListNode = new CommandListNode();
        this.commandListNode.parse(context);
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
