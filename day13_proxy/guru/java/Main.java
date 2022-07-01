import java.time.Duration;
import java.time.Instant;

import downloader.YouTubeDownloader;
import proxy.YouTubeCacheProxy;
import some_cool_media_library.ThirdPartyYouTubeClass;


public class Main {
  public static void main(String[] args) {
    YouTubeDownloader naiveDownloader = new YouTubeDownloader(new ThirdPartyYouTubeClass());
    YouTubeDownloader smartDownloader = new YouTubeDownloader(new YouTubeCacheProxy());

    long naive = testSpeed(naiveDownloader);
    long smart = testSpeed(smartDownloader);
    System.out.format("Time saved by caching proxy: %dms\n", (naive - smart));
  }

  private static long testSpeed(final YouTubeDownloader downloader) {
    final Instant startTime = Instant.now();

    /* User behavior in our app: */
    downloader.renderPopularVideos();
    downloader.renderVideoPage("catzzzzzzzzz");
    downloader.renderPopularVideos();
    downloader.renderVideoPage("dancesvideoo");
    /* User might visit the same page quite often. */
    downloader.renderVideoPage("catzzzzzzzzz");
    downloader.renderVideoPage("someothervid");

    final long estimatedTime = Duration.between(startTime, Instant.now()).toMillis();
    System.out.format("Time elapsed: %dms\n", estimatedTime);
    return estimatedTime;
  }
}
