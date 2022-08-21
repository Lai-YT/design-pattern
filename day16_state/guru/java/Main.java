import ui.Player;
import ui.UI;

/// Everything comes together here.
public class Main {
  public static void main(final String[] args) {
    final Player player = new Player();
    final UI ui = new UI(player);
    ui.init();
  }
}
