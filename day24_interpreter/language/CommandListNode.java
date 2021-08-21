package language;

import java.util.ArrayList;
import language.CommandNode;
import language.Context;
import language.ParseException;
import language.Node;


/*
 * <command list> ::= <command>*
 */
public class CommandListNode extends Node {
    private ArrayList<CommandNode> list = new ArrayList<>();

    @Override
    public void parse(Context context) throws ParseException {
        while (true) {
            if (context.currentToken() == null) {
                throw new ParseException("Missing 'end'");
            } else if (context.currentToken().equals("end")) {
                context.skipToken("end");
                break;
            } else {
                CommandNode commandNode = new CommandNode();
                commandNode.parse(context);
                this.list.add(commandNode);
            }
        }
    }

    @Override
    public String toString() {
        return this.list.toString();
    }
}
