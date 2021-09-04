package strategy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

import strategy.PayStrategy;


/**
 * Concrete strategy. Implements PayPal payment method.
 */
public class PayByPayPal implements PayStrategy {
    private static final Map<String, String> DATA_BASE = new HashMap<>();
    private final BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));

    private String email;
    private String password;
    private boolean signedIn;

    static {
        PayByPayPal.DATA_BASE.put("amanda1985", "amanda@ya.com");
        PayByPayPal.DATA_BASE.put("qwerty", "john@amazon.eu");
    }

    /**
     * Collect customer's data.
     */
    @Override
    public void collectPaymentDetails() {
        try {
            while (!this.signedIn) {
                System.out.print("Enter the user's email: ");
                this.email = this.READER.readLine();
                System.out.print("Enter the password: ");
                this.password = this.READER.readLine();

                if (this.verify()) {
                    System.out.println("Data verification has been successful.");
                } else {
                    System.out.println("Wrong email or password!");
                }
            }
        } catch (final IOException e) {
            e.printStackTrace();
        }
    }

    private boolean verify() {
        this.signedIn = this.email.equals(PayByPayPal.DATA_BASE.get(this.password));
        return this.signedIn;
    }

    /**
     * Save customer  data for future shopping attempts.
     */
    @Override
    public boolean pay(final int paymentAmount) {
        if (this.signedIn) {
            System.out.println("Paying " + paymentAmount + " using PayPal.");
            return true;
        } else {
            return false;
        }
    }
}
