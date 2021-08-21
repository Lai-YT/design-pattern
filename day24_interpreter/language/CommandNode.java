package language;

import language.Context;
import language.Node;
import language.ParseException;
import language.PrimitiveCommandNode;
import language.RepeatCommandNode;


/*
 * <command> ::= <repeat command> | <primitive command>
 */
public class CommandNode extends Node {
    private Node node;

    @Override
    public void parse(final Context context) throws ParseException {
        this.node = context.currentToken().equals("repeat")
                    ? new RepeatCommandNode()
                    : new PrimitiveCommandNode();
        this.node.parse(context);
    }

    public String toString() {
        return this.node.toString();
    }
}
