package proxy;

import some_cool_media_library.ThirdPartyYouTubeClass;
import some_cool_media_library.ThirdPartyYouTubeLib;
import some_cool_media_library.Video;

import java.util.HashMap;

/**
 * Caching proxy.
 */
public class YouTubeCacheProxy implements ThirdPartyYouTubeLib {
  private ThirdPartyYouTubeLib youtubeService;
  private HashMap<String, Video> cachePopular = new HashMap<>();
  private HashMap<String, Video> cacheAll = new HashMap<>();

  public YouTubeCacheProxy() {
    this.youtubeService = new ThirdPartyYouTubeClass();
  }

  @Override
  public HashMap<String, Video> popularVideos() {
    if (this.cachePopular.isEmpty()) {
      this.cachePopular = this.youtubeService.popularVideos();
    } else {
      System.out.println("Retrieved list from cache.");
    }
    return this.cachePopular;
  }

  @Override
  public Video getVideo(final String videoId) {
    Video video = this.cacheAll.get(videoId);
    if (video == null) {
      video = this.youtubeService.getVideo(videoId);
      this.cacheAll.put(videoId, video);
    } else {
      System.out.format("Retrieved video '%s' from cache.\n", videoId);
    }
    return video;
  }

  public void reset() {
    this.cachePopular.clear();
    this.cacheAll.clear();
  }
}
