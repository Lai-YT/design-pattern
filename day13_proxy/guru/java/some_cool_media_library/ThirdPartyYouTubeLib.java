package some_cool_media_library;

import java.util.HashMap;

/**
 * Remote service interface.
 */
public interface ThirdPartyYouTubeLib {
  HashMap<String, Video> popularVideos();

  Video getVideo(final String videoId);
}
