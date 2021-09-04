package strategy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import strategy.CreditCard;
import strategy.PayStrategy;


/**
 * Concrete strategy. Implements credit card payment method.
 */
public class PayByCreditCard implements PayStrategy {
    private final BufferedReader READER = new BufferedReader(new InputStreamReader(System.in));
    private CreditCard card;

    /**
     * Collect credit card state.
     */
    @Override
    public void collectPaymentDetails() {
        try {
            System.out.print("Enter the card number: ");
            final String number = this.READER.readLine();
            System.out.print("Enter the card expiration date 'mm/yy': ");
            final String date = this.READER.readLine();
            System.out.print("Enter the CVV code: ");
            final String cvv = this.READER.readLine();
            this.card = new CreditCard(number, date, cvv);

            /* Validate credit card number... */

        } catch (final IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * After card validation we can charge customer's credit card.
     */
    @Override
    public boolean pay(final int paymentAmount) {
        if (this.cardIsPresent()) {
            System.out.println("Paying " + paymentAmount + " using Credit Card.");
            this.card.setAmount(this.card.getAmount() - paymentAmount);
            return true;
        } else {
            return false;
        }
    }

    private boolean cardIsPresent() {
        return this.card != null;
    }

}
