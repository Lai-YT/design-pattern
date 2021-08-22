package language;

import language.CommandListNode;
import language.Context;
import language.ExecuteException;
import language.Node;
import language.ParseException;


/*
 * <repeat command> ::= repeat <number> <command list>
 */
public class RepeatCommandNode extends Node {
    private int number;
    private CommandListNode commandListNode;

    @Override
    public void parse(final Context context) throws ParseException {
        context.skipToken("repeat");
        this.number = context.currentNumber();
        context.nextToken();
        this.commandListNode = new CommandListNode();
        this.commandListNode.parse(context);
    }

    @Override
    public void execute() throws ExecuteException {
        for (int i = 0; i < number; ++i) {
            commandListNode.execute();
        }
    }

    @Override
    public String toString() {
        return "[repeat " + this.number + " " + this.commandListNode + "]";
    }
}
