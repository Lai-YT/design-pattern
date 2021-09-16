package listener;

import java.io.File;

import listener.EventListener;


/**
 * Writes a message to a log upon receiving notification.
 */
public class LogOpenListener implements EventListener {
    private File log;

    public LogOpenListener(final String fileName) {
        this.log = new File(fileName);
    }

    @Override
    public void update(final String eventType, final File file) {
        System.out.println("Save to log " + this.log + ": Someone has performed "
                + eventType + " operation with the following file: " + file.getName());
    }
}
