import java.io.File;

import facade.VideoConversionFacade;

public class Main {
    public static void main(String[] args) {
        final VideoConversionFacade converter = new VideoConversionFacade();
        File mp4Video = converter.convertVideo("youtube-video.ogg", "mp4");
    }
}
