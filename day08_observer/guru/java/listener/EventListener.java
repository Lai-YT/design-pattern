package listener;

import java.io.File;


/**
 * Common observer interface.
 */
public interface EventListener {
    void update(final String eventType, final File file);
}
