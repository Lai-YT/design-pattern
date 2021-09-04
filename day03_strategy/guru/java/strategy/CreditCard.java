package strategy;


/**
 * Dummy credit card class.
 */
public class CreditCard {
    private int amount;
    private String number;
    private String date;
    private String cvv;

    CreditCard(final String number, final String date, final String cvv) {
        this.amount = 100_000;
        this.number = number;
        this.date = date;
        this.cvv = cvv;
    }

    public void setAmount(final int amount) {
        this.amount = amount;
    }

    public int getAmount() {
        return this.amount;
    }
}
