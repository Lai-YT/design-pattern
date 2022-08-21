package states;

import ui.Player;

/// Concrete states provide the special implementation for all interface methods.
public class LockedState extends State {
    public static final String MESSAGE = "Locked...";

    public LockedState(final Player player) {
        super(player);
    }

    @Override
    public String onLock() {
        if (player.isPlaying()) {
            player.changeState(new ReadyState(player));
            return "Stop playing";
        }
        return MESSAGE;
    }

    @Override
    public String onPlay() {
        player.changeState(new ReadyState(player));
        return "Ready";
    }

    @Override
    public String onNext() {
        return MESSAGE;
    }

    @Override
    public String onPrev() {
        return MESSAGE;
    }
}
