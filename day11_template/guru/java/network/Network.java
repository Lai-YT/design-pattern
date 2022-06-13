package network;


/**
 * Base class of social network.
 */
public abstract class Network {
    protected String userName;
    protected String password;

    /**
     * Publish the data to whatever network.
     * This is the `Template Method`, marked `final` so can't be overridden.
     */
    final public boolean post(final String message) {
        /* Authenticate before posting.
            Every network uses a different authentication method. */
        if (this.logIn()) {
            /* Send the post data. */
            boolean result = this.sendData(message.getBytes());
            this.logOut();
            return result;
        }
        return false;
    }

    protected abstract boolean logIn();
    protected abstract boolean sendData(final byte[] data);
    protected abstract void logOut();
}
