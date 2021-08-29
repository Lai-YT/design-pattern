/*
 * https://refactoring.guru/design-patterns/factory-method/java/example
 */

import factory.Dialog;
import factory.HtmlDialog;
import factory.WindowsDialog;

/*
 * Client code. Everything comes together here.
 */
public class Main {
    private static Dialog dialog;

    public static void main(String[] args) {
        Main.configure();
        Main.runBusinessLogic();
    }

    /**
     * The concrete factory is usually chosen depending on configuration or
     * environment options.
     */
    private static void configure() {
        if (System.getProperty("os.name").equals("Windows 10")) {
            Main.dialog = new WindowsDialog();
        } else {
            Main.dialog = new HtmlDialog();
        }
    }

    /**
     * All of the client code should work with factories and products through
     * abstract interfaces. This way it does not care which factory it works
     * with and what kind of product it returns.
     */
     private static void runBusinessLogic() {
         Main.dialog.renderWindow();
     }
}
