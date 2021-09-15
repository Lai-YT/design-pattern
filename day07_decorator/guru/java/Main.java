import decorator.CompressionDecorator;
import decorator.DataSource;
import decorator.DataSourceDecorator;
import decorator.EncryptionDecorator;
import decorator.FileDataSource;


public class Main {
    public static void main(String[] args) {
        String salaryRecords = "Name, Salary" + "\n"
                + "John Smith, 100000" + "\n"
                + "Steven Jobs, 912000";
        DataSource plain = new FileDataSource("Encode.txt");
        DataSourceDecorator encoded =
                new CompressionDecorator(new EncryptionDecorator(plain));
        /* Writes the encoded data to Encode.txt. */
        encoded.writeData(salaryRecords);

        System.out.println("- Input -----");
        System.out.println(salaryRecords);         /* Shows the original data. */
        System.out.println("- Encoded ---");
        System.out.println(plain.readData());      /* Reads out the data (encoded) without modification. */
        System.out.println("- Decoded ---");
        System.out.println(encoded.readData());    /* Reads out the data but decode them. */
    }
}
