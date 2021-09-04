package order;

import strategy.PayStrategy;


/**
 * Order class. Doesn't know the concrete payment method (strategy) user has
 * picked. It uses common strategy interface to delegate collecting payment data
 * to strategy object. It can be used to save order to database.
 */
public class Order {
    private int totalCost = 0;
    private boolean isClosed = false;

    public void processOrder(final PayStrategy strategy) {
        strategy.collectPaymentDetails();
        /* Here we could collect and store payment data from the strategy. */
    }

    public void setTotalCost(final int cost) {
        this.totalCost += cost;
    }

    public int getTotalCost() {
        return this.totalCost;
    }

    public boolean isClosed() {
        return this.isClosed;
    }

    public void setClosed() {
        this.isClosed = true;
    }
}
