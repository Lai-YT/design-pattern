package decorator;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.Base64;
import java.util.zip.Deflater;
import java.util.zip.DeflaterOutputStream;
import java.util.zip.InflaterInputStream;

import decorator.DataSource;
import decorator.DataSourceDecorator;


public class CompressionDecorator extends DataSourceDecorator {
    private int compLevel;

    /* Java does not support default arguments, so overloading is used. */
    public CompressionDecorator(final DataSource source) {
        /* constructor-telescoping */
        this(source, 6);
    }

    public CompressionDecorator(final DataSource source, final int compLevel) {
        super(source);
        this.compLevel = compLevel;
    }

    @Override
    public void writeData(final String data) {
        super.writeData(this.compress(data));
    }

    @Override
    public String readData() {
        return this.decompress(super.readData());
    }

    private String compress(final String data) {
        byte[] result = data.getBytes();
        try (ByteArrayOutputStream bout = new ByteArrayOutputStream(512);
                    DeflaterOutputStream dout = new DeflaterOutputStream(bout, new Deflater(this.compLevel))) {
            dout.write(result);
            /*
             * This close() on DeflaterOutputStream is necessary.
             * The stream only knows to compress and write the last bytes when
             * you tell it to close.
             */
            dout.close();
            return Base64.getEncoder().encodeToString(bout.toByteArray());
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
            return null;
        }
    }

    private String decompress(final String data) {
        byte[] result = Base64.getDecoder().decode(data);
        try (ByteArrayInputStream bin = new ByteArrayInputStream(result);
                    InflaterInputStream iin = new InflaterInputStream(bin);
                    ByteArrayOutputStream bout = new ByteArrayOutputStream(512)) {
            int b;
            while ((b = iin.read()) != -1) {
                bout.write(b);
            }
            return new String(bout.toByteArray());
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
            return null;
        }
    }
}
