package states;

import ui.Player;

/// They can also trigger state transitions in the context.
public class ReadyState extends State {
    public ReadyState(final Player player) {
        super(player);
    }

    @Override
    public String onLock() {
        player.changeState(new LockedState(player));
        return LockedState.MESSAGE;
    }

    @Override
    public String onPlay() {
        player.changeState(new PlayingState(player));
        return player.startPlayback();
    }

    @Override
    public String onNext() {
        return LockedState.MESSAGE;
    }

    @Override
    public String onPrev() {
        return LockedState.MESSAGE;
    }
}
