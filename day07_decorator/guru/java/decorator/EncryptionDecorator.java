package decorator;

import java.util.Base64;

import decorator.DataSource;
import decorator.DataSourceDecorator;


public class EncryptionDecorator extends DataSourceDecorator {
    public EncryptionDecorator(final DataSource source) {
        super(source);
    }

    @Override
    public void writeData(final String data) {
        super.writeData(this.encode(data));
    }

    @Override
    public String readData() {
        return this.decode(super.readData());
    }

    private String encode(final String data) {
        byte[] result = data.getBytes();
        for (byte r : result) {
            r += (byte) 1;
        }
        return Base64.getEncoder().encodeToString(result);
    }

    private String decode(final String data) {
        byte[] result = Base64.getDecoder().decode(data);
        for (byte r : result) {
            r -= (byte) 1;
        }
        return new String(result);
    }
}
