package downloader;


import some_cool_media_library.ThirdPartyYouTubeLib;
import some_cool_media_library.Video;

import java.util.HashMap;

/**
 * Media downloader app.
 */
public class YouTubeDownloader {
  private ThirdPartyYouTubeLib api;

  /**
   * @param api Can be either a real service object or a proxy object
   */
  public YouTubeDownloader(ThirdPartyYouTubeLib api) {
    this.api = api;
  }

  public void renderVideoPage(final String videoId) {
    Video video = this.api.getVideo(videoId);
    System.out.println("\n-------------------------------");
    System.out.println("Video page (imagine fancy HTML)");
    System.out.format("ID: %s\n", video.id);
    System.out.format("Title: %s\n", video.title);
    System.out.format("Video: %s\n", video.data);
    System.out.println("-------------------------------");
    System.out.println();
  }

  public void renderPopularVideos() {
    HashMap<String, Video> list = this.api.popularVideos();
    System.out.println("\n-------------------------------");
    System.out.println("Most popular videos on YouTube (imagine fancy HTML)");
    for (final Video video : list.values()) {
      System.out.format("ID: %s / Title: %s\n", video.id, video.title);
    }
    System.out.println("-------------------------------");
    System.out.println();
  }
}
