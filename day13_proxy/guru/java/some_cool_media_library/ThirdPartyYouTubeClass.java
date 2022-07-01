package some_cool_media_library;

import java.util.HashMap;

/**
 * Remote service implementation.
 */
public class ThirdPartyYouTubeClass implements ThirdPartyYouTubeLib {
  @Override
  public HashMap<String, Video> popularVideos() {
    this.connectToServer("https://www.youtube.com");
    return this.getRandomVideos();
  }

  @Override
  public Video getVideo(final String videoId) {
    this.connectToServer(String.format("https://www.youtube.com/%s", videoId));
    return this.getSomeVideo(videoId);
  }

  /* -----------------------------------------------------------------------
   * Fake methods to simulate network activity. They as slow as a real life.
   */

   private int random(final int min, final int max) {
    return min + (int) (Math.random() * ((max - min) + 1));
   }

   private void experienceNetworkLatency() {
    final int randomLatency = this.random(5, 10);
    for (int i = 0; i < randomLatency; i++) {
      try {
        Thread.sleep(100);
      } catch (InterruptedException ex) {
        ex.printStackTrace();
      }
    }
   }

   private void connectToServer(final String server) {
    System.out.format("Connecting to %s... ", server);
    this.experienceNetworkLatency();
    System.out.println("Connected!");
  }

  private HashMap<String, Video> getRandomVideos() {
    System.out.print("Downloading populars... ");

    this.experienceNetworkLatency();
    final HashMap<String, Video> hmap = new HashMap<>();
    hmap.put("catzzzzzzzzz", new Video("sadgahasgdas", "Catzzzz.avi"));
    hmap.put("mkafksangasj", new Video("mkafksangasj", "Dog-play-with-ball.mp4"));
    hmap.put("dancesvideoo", new Video("asdfas3ffasd", "Dancing-video.mpq"));
    hmap.put("dlsdk5jfslaf", new Video("dlsdk5jfslaf", "Barcelona-vs-RealM.mov"));
    hmap.put("3sdfgsd1j333", new Video("3sdfgsd1j333", "Programing-lesson#1.avi"));

    System.out.println("Done!");
    return hmap;
  }

  private Video getSomeVideo(final String videoId) {
    System.out.print("Downloading video... ");

    this.experienceNetworkLatency();
    Video video = new Video(videoId, "Some video title");

    System.out.println("Done!");
    return video;
  }
}
