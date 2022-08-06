package some_complex_media_library;

public class VideoFile {
    public final String name;
    public final String codecType;

    public VideoFile(final String name) {
        this.name = name;
        this.codecType = name.substring(name.indexOf(".") + 1);
    }
}
