package decorator;


/**
 * A common data interface, which defines read and write operations.
 */
public interface DataSource {
    void writeData(final String data);
    String readData();
}
