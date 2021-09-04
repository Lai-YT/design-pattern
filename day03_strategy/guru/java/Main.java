import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

import order.Order;
import strategy.PayByCreditCard;
import strategy.PayByPayPal;
import strategy.PayStrategy;


/**
 * World first console e-commerce application.
 */
public class Main {
    private static Map<Integer, Integer> priceOnProducts = new HashMap<>();
    private static Order order = new Order();
    private static PayStrategy strategy;

    static {
        Main.priceOnProducts.put(1, 2200);
        Main.priceOnProducts.put(2, 1850);
        Main.priceOnProducts.put(3, 1100);
        Main.priceOnProducts.put(4, 890);
    }

    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            while (!Main.order.isClosed()) {
                int cost = 0;

                String continueChoice;
                do {
                    System.out.print("Please select a product:" + "\n" +
                            "1 - Mother board\n" +
                            "2 - CPU" + "\n" +
                            "3 - HDD" + "\n" +
                            "4 - Memory" + "\n");
                    final int choice = Integer.parseInt(reader.readLine());
                    cost = Main.priceOnProducts.get(choice);
                    System.out.print("Count: ");
                    final int count = Integer.parseInt(reader.readLine());
                    Main.order.setTotalCost(cost * count);
                    System.out.print("Do you wish to continue selecting products? Y/N: ");
                    continueChoice = reader.readLine();
                } while (continueChoice.equalsIgnoreCase("Y"));

                if (Main.strategy == null) {
                    System.out.print("Please select a payment method:" + "\n" +
                            "1 - PayPal" + "\n" +
                            "2 - Credit Card" + "\n");
                    String paymentMethod = reader.readLine();

                    /*
                     * Client creates different strategies based on input from user,
                     * application configuration, etc.
                     */
                    if (paymentMethod.equals("1")) {
                        Main.strategy = new PayByPayPal();
                    } else {
                        Main.strategy = new PayByCreditCard();
                    }
                }

                /*
                 * Order object delegates gathering payment data to strategy object,
                 * since only strategies know what data they need to process a
                 * payment.
                 */
                Main.order.processOrder(Main.strategy);

                System.out.print("Pay " + Main.order.getTotalCost() + " units or Continue shopping? P/C: ");
                final String proceed = reader.readLine();
                if (proceed.equalsIgnoreCase("p")) {
                    /* Finally. strategy handles the payment. */
                    if (Main.strategy.pay(Main.order.getTotalCost())) {
                        System.out.println("Payment has been successful.");
                    } else {
                        System.out.println("Fail! Please, check your data.");
                    }
                    Main.order.setClosed();
                }
            }  /* while-loop */
        }  /* try-block */
    }  /* end main */
}
