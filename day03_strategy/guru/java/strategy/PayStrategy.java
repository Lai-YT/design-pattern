package strategy;


/**
 * Common interface of payment methods.
 */
public interface PayStrategy {
    boolean pay(final int paymentAmount);
    void collectPaymentDetails();
}
