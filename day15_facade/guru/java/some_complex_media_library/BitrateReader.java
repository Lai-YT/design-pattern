package some_complex_media_library;

public class BitrateReader {
    public static VideoFile read(final VideoFile file, final Codec codec) {
        System.out.println("BitrateReader: reading file...");
        return file;
    }

    public static VideoFile convert(VideoFile buffer, final Codec codec) {
        System.out.println("BitrateReader: writing file...");
        return buffer;
    }
}
