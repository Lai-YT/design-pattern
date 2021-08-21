package language;

import java.util.StringTokenizer;
import language.ParseException;


public class Context {
    private StringTokenizer tokenizer;
    private String currentToken;

    public Context(final String text) {
        this.tokenizer = new StringTokenizer(text);
        this.nextToken();
    }

    public String nextToken() {
        return this.tokenizer.hasMoreTokens()
               ? (this.currentToken = tokenizer.nextToken())
               : (this.currentToken = null);
    }

    public String currentToken() {
        return this.currentToken;
    }

    public void skipToken(final String token) throws ParseException {
        if (!token.equals(this.currentToken)) {
            throw new ParseException(
                "Warning: " + token + " is expected, but " + this.currentToken + " is found."
            );
        }
        this.nextToken();
    }

    public int currentNumber() throws ParseException {
        try {
            return Integer.parseInt(this.currentToken);
        } catch (final NumberFormatException e) {
            throw new ParseException("Warning: " + e);
        }
    }
}
