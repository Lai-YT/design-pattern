package language;

import java.util.Set;
import language.Context;
import language.Node;
import language.ParseException;


/*
 * <primitive command> ::= go | right | left
 */
public class PrimitiveCommandNode extends Node {
    private String command;
    public static final Set<String> COMMANDS = Set.of("go", "right", "left");

    @Override
    public void parse(final Context context) throws ParseException {
        this.command = context.currentToken();
        context.skipToken(this.command);

        if (!PrimitiveCommandNode.COMMANDS.contains(this.command)) {
            throw new ParseException(this.command + " is undefined");
        }
    }

    @Override
    public String toString() {
        return this.command;
    }
}
