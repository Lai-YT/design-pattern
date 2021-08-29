package factory;

import button.Button;
import button.WindowsButton;
import factory.Dialog;

/**
 * Winodws Dialog will produce Windows buttons.
 */
public class WindowsDialog extends Dialog {
    @Override
    public Button createButton() {
        return new WindowsButton();
    }
}
