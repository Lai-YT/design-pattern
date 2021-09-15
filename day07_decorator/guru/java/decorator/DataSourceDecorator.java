package decorator;

import decorator.DataSource;


/**
 * Abstract base decorator.
 */
public class DataSourceDecorator implements DataSource {
    private DataSource wrappee;

    /*
     * Package-only since this is a base decorator that only do the wrapping,
     * it's constructor shouldn't be called directly in the client code.
     */
    DataSourceDecorator(final DataSource source) {
        this.wrappee = source;
    }

    @Override
    public void writeData(final String data) {
        this.wrappee.writeData(data);
    }

    @Override
    public String readData() {
        return this.wrappee.readData();
    }
}
