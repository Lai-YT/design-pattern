package decorator;

import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.File;
import java.io.IOException;

import decorator.DataSource;


/**
 * Simple data reader-writer.
 */
public class FileDataSource implements DataSource {
    private String name;

    public FileDataSource(final String name) {
        this.name = name;
    }

    @Override
    public void writeData(final String data) {
        File file = new File(name);
        try (FileOutputStream fos = new FileOutputStream(file)) {
            fos.write(data.getBytes(), 0, data.length());
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
    }

    @Override
    public String readData() {
        char[] buffer = null;
        File file = new File(name);
        try (FileReader reader = new FileReader(file)) {
            buffer = new char[(int) file.length()];
            reader.read(buffer);
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
        return new String(buffer);
    }
}
