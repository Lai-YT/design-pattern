package some_cool_media_library;


public class Video {
  final public String id;
  final public String title;
  final public String data;

  Video(final String id, final String title) {
    this.id = id;
    this.title = title;
    this.data = "Random video.";
  }
}
