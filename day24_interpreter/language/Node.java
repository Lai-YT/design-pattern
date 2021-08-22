package language;

import language.Context;
import language.Executor;
import language.ParseException;


/*
 * The is the basic unit, which all command nodes should inherits from.
 */
public abstract class Node implements Executor {
    public abstract void parse(final Context context) throws ParseException;
    public abstract String toString();
}
