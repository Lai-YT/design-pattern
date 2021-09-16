package editor;

import java.io.File;

import publisher.EventManager;


/**
 * Concrete publisher, tracked by other objects.
 */
public class Editor {
    public EventManager events;
    private File file;

    public Editor() {
        this.events = new EventManager("open", "save");
    }

    public void openFile(final String filePath) {
        this.file = new File(filePath);
        this.events.notify("open", this.file);
    }

    public void saveFile() throws Exception {
        if (this.file != null) {
            this.events.notify("save", file);
        } else {
            throw new Exception("Please open a file first.");
        }
    }
}
