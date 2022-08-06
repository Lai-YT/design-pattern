package some_complex_media_library;

public class CodecFactory {
    public static Codec extract(final VideoFile file) {
        Codec codec = null;
        if (file.codecType.equals("mp4")) {
            codec = new Mpeg4CompressionCodec();
        } else {
            codec = new OggCompressionCodec();
        }
        System.out.format("CodecFactory: extracting %s audio...\n", file.codecType);
        return codec;
    }
}
