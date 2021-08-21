import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import language.Context;
import language.ProgramNode;


public class Main {
    public static void main(String[] args) {
        /* try-with-resource */
        try (BufferedReader reader = new BufferedReader(new FileReader("program.txt"));
                BufferedWriter writer = new BufferedWriter(new FileWriter("interpreted.txt", false))) {
            String text;
            while ((text = reader.readLine()) != null) {
                writer.write("text = \"" + text + "\"\n");
                ProgramNode node = new ProgramNode();
                node.parse(new Context(text));
                writer.write("node = " + node + "\n");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
