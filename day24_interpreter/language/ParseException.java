package language;


/*
 * This is the exception thrown if any error occurs during parsing.
 */
public class ParseException extends Exception {
    public ParseException(final String msg) {
        super(msg);
    }
}
