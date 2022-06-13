import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import network.Facebook;
import network.Network;
import network.Twitter;


public class Main {
    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            Network network = null;

            System.out.print("Input user name: ");
            String userName = reader.readLine();
            System.out.print("Input password: ");
            String password = reader.readLine();

            /* Enter the message. */
            System.out.print("Input message: ");
            String message = reader.readLine();

            System.out.println("\nChoose social network for posting message.\n" +
                    "1 - Facebook\n" +
                    "2 - Twitter");
            int choice = Integer.parseInt(reader.readLine());

            /* Create proper network object and send the message. */
            switch (choice) {
                case 1:
                    network = new Facebook(userName, password);
                    break;
                case 2:
                    network = new Twitter(userName, password);
                    break;
                default:
                    System.err.println("unknown social network");
                    return;
            }
            network.post(message);
        }
    }
}
